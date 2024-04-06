#include<iostream>
#include<SFML/Graphics.hpp>

const int wHeight = 480;
const int wWidth = 600;


int main(){


    
    sf::RenderWindow window;
    window.create(sf::VideoMode(wWidth, wHeight), "Pong");
    window.setFramerateLimit(60);

    //Properties for Paddle 1
    float paddle1Speed = 10.0f;
    float paddle1Ypos = 200.0f;
    float paddle1Xpos = 20.0f;
    bool movingUp1 = false, movingDown1 = false;
    
    //Properties for Paddle 2
    float paddle2Speed = 10.0f;
    float paddle2Ypos = 200.0f;
    float paddle2Xpos = 570.0f;
    bool movingUp2 = false, movingDown2 = false;

    //Properties for Ball
    int ballrad = 10;
    float ballstartX = 280, ballstartY = 220;
    float ballMoveSpeed = 30;
    float ballSideMoveSpeed = 0;

    //Paddle 1
    sf::RectangleShape paddle1(sf::Vector2f(10.0f, 60.0f));
    paddle1.setPosition(sf::Vector2f(paddle1Xpos, paddle1Ypos));

    //Paddle 2
    sf::RectangleShape paddle2(sf::Vector2f(10.0f, 60.0f));
    paddle2.setPosition(sf::Vector2f(paddle2Xpos, paddle2Ypos));

    //Ball
    sf::CircleShape ball(ballrad);
    ball.setPosition(ballstartX, ballstartY); 

    sf::Event event;
    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            //Movement For player 1
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::W){
                    movingUp1 = true;
                }

                if(event.key.code == sf::Keyboard::S)
                {
                    movingDown1 = true;
                }
            }
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::W)
                {
                    movingUp1 = false;
                }
                if(event.key.code == sf::Keyboard::S)
                {
                    movingDown1 = false;
                }
            }
            
           
        }


        // //Movement for player 2
          if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Up){
                    movingUp2 = true;
                }

                if(event.key.code == sf::Keyboard::Down)
                {
                    movingDown2 = true;
                }
            }
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Up)
                {
                    movingUp2 = false;
                }
                if(event.key.code == sf::Keyboard::Down)
                {
                    movingDown2 = false;
                }
            }


        if(movingUp1){
            paddle1.setPosition(paddle1Xpos, paddle1.getPosition().y + -paddle1Speed);
        }
        if(!movingUp1){
            paddle1.setPosition(paddle1Xpos, paddle1.getPosition().y);
        }
        if(movingDown1){
            paddle1.setPosition(paddle1Xpos, paddle1.getPosition().y + paddle1Speed);
        }
        if(!movingDown1){
            paddle1.setPosition(paddle1Xpos, paddle1.getPosition().y );
        }

        if(movingUp2){
            paddle2.setPosition(paddle2Xpos, paddle2.getPosition().y + -paddle2Speed);
        }
        if(!movingUp2){
            paddle2.setPosition(paddle2Xpos, paddle2.getPosition().y);
        }
        if(movingDown2){
            paddle2.setPosition(paddle2Xpos, paddle2.getPosition().y + paddle2Speed);
        }
        if(!movingDown2){
            paddle2.setPosition(paddle2Xpos, paddle2.getPosition().y );
        }


        //Ball Movement
        int count = 0;
        ball.setPosition(ball.getPosition().x + ballMoveSpeed, ball.getPosition().y + ballSideMoveSpeed);
        if(ball.getPosition().x > 550){
            if(ball.getPosition().y > paddle2.getPosition().y && ball.getPosition().y < paddle2.getPosition().y + 60){
                ballMoveSpeed = -10;
                if (std::rand() % 2 == 0) {
                ballMoveSpeed = -10;
                 }

    // Generate a random initial speed for the ball's side movement
                ballSideMoveSpeed = (std::rand() % 2 == 0) ? 3 : -5;

            }
        }
        if(ball.getPosition().x < 30){
            if(ball.getPosition().y > paddle1.getPosition().y && ball.getPosition().y < paddle1.getPosition().y + 60){
                ballMoveSpeed = 10;
                if (std::rand() % 2 == 0) {
                ballMoveSpeed = -10;
                 }

                // Generate a random initial speed for the ball's side movement
                ballSideMoveSpeed = (std::rand() % 2 == 0) ? 3 : -5;
            }
        }

        if(ball.getPosition(). y < 0){
            ballSideMoveSpeed = 10;
        }
        if(ball.getPosition().y > wHeight - 20){
            ballSideMoveSpeed = -10;
        }
        
        

        window.clear();
        window.draw(paddle1);
        window.draw(ball);
        window.draw(paddle2);
        window.display();
    }


}

