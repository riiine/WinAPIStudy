/** ���ڿ� ���� ���̺귯��*/
#include <string>
/** SFML Graphics ���� ���̺귯��*/
#include <SFML/Graphics.hpp>

/** C++ ǥ�� ���̺귯���� ����մϴ�. */
using namespace std;
/** SFML ���̺귯���� ����մϴ�. */
using namespace sf;

/**
���� ���̿� ���� ������ ����� ������ �ݴϴ�.
��ó����� ����� ������ ���� �빮�ڷ� �� �ݴϴ�.
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