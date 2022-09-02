/** 문자열 관련 라이브러리*/
#include <string>
/** SFML Graphics 관련 라이브러리*/
#include <SFML/Graphics.hpp>

/** C++ 표준 라이브러리를 사용합니다. */
using namespace std;
/** SFML 라이브러리를 사용합니다. */
using namespace sf;

/**
가로 길이와 세로 길이의 상수를 정의해 줍니다.
전처리기로 상수를 정의할 때는 대문자로 해 줍니다.
*/
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

int main()
{
 
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird");

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.clear();
                break;
            default:
                break;
            }
        }

        window.clear();
        window.display();
    }

}