#pragma once

/** ���ڿ� ���� ���̺귯�� */
#include <string>
/** SFML Graphics ���� ���̺귯��*/
#include <SFML/Graphics.hpp>

/**
key�� value�� ������ map �����̳� ���� ���̺귯��
��������Ʈ��� ��Ʈ���� �����մϴ�.
*/
#include <map>

/** C++ ǥ�� ���̺귯�� ����մϴ�. */
using namespace std;
/** SFML ���̺귯�� ����մϴ�. */
using namespace sf;

namespace FlappyBirdGame
{
	/** �̹������ ��Ʈ, ������� �����ϴ� �Ŵ��� Ŭ�����Դϴ�. */
	class AssetManager
	{
	public:
		/** ������ �Լ��� �������ݴϴ�. */
		AssetManager() {}
		/** �Ҹ��� �Լ��� �������ݴϴ�. */
		~AssetManager() {}

		/**
		map �����̳ʿ��� Ű�� �̿��� �ؽ��ĸ� �ε��ؼ� �������ݴϴ�.
		_textures map �����̳ʿ� name�� Ű�� �ؼ� texture�� �߰����ִ� �Լ��� ������ �����մϴ�.
		�����ο��� ������ �־�� �մϴ�.
		*/
		void LoadTexture(string name, string fileName);

		/**
		�� ������ ������ ��ȯ���� �ʰ� �����ڷ� ��ȯ�ұ��?
		�����ڴ� C��� ���� �������ϴ�.
		C++���� �߰��� �����Դϴ�.
		C++���� �����Ϳ� �����ڴ� ����ѵ�, �� �����ڸ� ���� �����?
		�����ʹ� ����� �ٲ� ���� �ֽ��ϴ�. �޸� ������ ������ �� �� �ֽ��ϴ�. 
		�����ڴ� ��� ���� ��Ī�� �� �� �������ָ� ����� �ٲ��� ���մϴ�.
		�޸� ������ �������ϴ�. 
		*/
		/**
		map �����̳ʿ��� �ʿ��� �ؽ��ĸ� �����ɴϴ�.
		_textures map �����̳ʿ��� name�� Ű�� value���� texture�� ��ȯ�ϴ� �Լ��� ������ �����մϴ�.
		*/
		sf::Texture& GetTexture(string name);

		/**
		���¿��� ��Ʈ�� �ε��ؼ� _fonts map �����̳ʿ� �����ϴ� �Լ��Դϴ�.
		map �����̳ʿ� ��Ʈ ������ �ε��ؼ� �������ݴϴ�.
		_fonts map �����̳ʿ� name�� Ű�� �ؼ� font�� �߰����ִ� �Լ��� ������ �����մϴ�.
		*/
		void LoadFont(string name, string fileName);

		/**
		map �����̳ʿ��� Ű�� �ʿ��� ��Ʈ�� �����ɴϴ�.
		_fonts map �����̳ʿ��� name�� Ű�� value���� font�� ��ȯ�ϴ� �Լ��� ������ �����մϴ�.
		*/
		sf::Font& GetFont(string name);

	private:
		/**
		�� vector�����̳ʸ� ���� �ʰ� map �����̳ʸ� �����?
		vector�����̳ʿ� ������ �ϸ� ���ϴ� ���� �������� ���ؼ��� �ݺ������� ���ǰ˻縦 �ؾ��մϴ�.
		map �����̳ʴ� Ű���� �˸� �ݺ����� ������ �ʰ��� ���ϴ� ���� ������ �� �ֽ��ϴ�.

		vector �����̳ʿ� ����Ǿ� �ִ� ���� �߿��� ���ϴ� ���� �������� ���ؼ��� �ݺ����� ������ �ʰ�
		LinQ ������ �̿��ϸ� �˴ϴ�. �ƽ��Ե� LinQ�� �ܺ� ���̺귯���Դϴ�.
		*/
		/** Texture���� �����ص� map �����̳� Ÿ���� ������ �����մϴ�. */
		map<string, sf::Texture> _textures;
		/** Font���� �����ص� map �����̳� Ÿ���� ������ �����մϴ�. */
		map<string, sf::Font> _fonts;
	};
}
