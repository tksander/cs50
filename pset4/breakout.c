//
// breakout.c2
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// height and width of game's paddle in pixels
#define pHEIGHT 10
#define pWIDTH  40

// height and width of game's bricks in pixels
#define bHEIGHT 5
#define bWIDTH 35

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);
void removeGWindow(GWindow window, GObject object);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    // initial velocity
    double Xvelocity = drand48();
    double  Yvelocity = 2.0;    

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {    
        
            // move circle along y-axis
            move(ball, Xvelocity, Yvelocity);

            // bounce off top edge of window
            if (getY(ball) <= 0)
            {
                Yvelocity = -Yvelocity;
            }
            
            //  ball hits bottom edge, lose life
            if (getY(ball) + getHeight(ball) >= getHeight(window))
            {
                lives = lives - 1;
                removeGWindow(window, ball);
                waitForClick();
                ball = initBall(window);
                pause(20);
                Yvelocity = -Yvelocity;
            }
            
            // bounce off right edge of window
            if (getX(ball) + getWidth(ball) >= getWidth(window))
            {
                Xvelocity = -Xvelocity;
            }

            // bounce off left edge of window
            if (getX(ball) <= 0)
            {
                Xvelocity = -Xvelocity;
            }

            // linger before moving again
            pause(10);
    
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);
        
        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure grect follows top cursor
                double x = getX(event) - pWIDTH / 2;
                double y = 500;
                setLocation(paddle, x, y);
            }
        }
       
       //check for ball collision 
       GObject object = detectCollision(window, ball);
       
       //if there was a collision
       if (object != NULL)
       {
       
            //if it collided with the paddle
            if (object == paddle)
            {
                Yvelocity = -Yvelocity;
            }
            
            //removes brick, updates scores
            else if (strcmp(getType(object), "GRect") == 0)
            {
                Yvelocity = -Yvelocity;
                
                removeGWindow(window, object);
                
                points = points + 1;
                
                updateScoreboard(window, label, points);
            }
            
            //Do not detect scoreboard
            if (strcmp(getType(object), "GLabel") == 0)
            {
                    return 0;
            }
        }
        
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{

int ybrick = 100;
int x = 0;
int xbrick = 3;


    // makes da bricks
    for (x = 0; x < ROWS; x++)
    {  
    
    ybrick = ybrick + 15;
        
        for(int y = 0; y < COLS; y++)
        {
            xbrick = (xbrick + 4);
            GRect brick = newGRect (xbrick, ybrick, bWIDTH, bHEIGHT);
            setFilled(brick, true);
            
            if (x == 0 || x == 2)
            {
                setColor(brick, "RED");
            }
            
            if (x == 1 || x == 3)
            {
                setColor(brick, "BLUE");
            }
            
            if (x == 4)
            {
                setColor(brick, "BLACK");
            }
         
            add(window, brick);
            xbrick = xbrick + bWIDTH;  
            
            if (y == 9)
            {
              xbrick = 3;  
            }
         }         
    }

}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // makes the ball
    GOval ball = newGOval (190, 450, 20, 20);
    setFilled(ball, true);
    setColor(ball, "BLUE");
    add(window, ball);
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // makes padde
    GRect paddle = newGRect ((200 - pWIDTH/2), 500, pWIDTH, pHEIGHT);
    setFilled(paddle, true);
    setColor(paddle, "RED");
    add(window, paddle);
    
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // Writes the points
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif-36");
    setColor(label, "GRAY");
     // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
    add(window, label);
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
    
    
}
