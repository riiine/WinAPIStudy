#pragma once

/** 문자열 관련 라이브러리 */
#include <string>
/** SFML Graphics 관련 라이브러리*/
#include <SFML/Graphics.hpp>

/**
key와 value를 가지는 map 컨테이너 관련 라이브러리
스프라이트들과 폰트들을 저장합니다.
*/
#include <map>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;
/** SFML 라이브러리 사용합니다. */
using namespace sf;

namespace FlappyBirdGame
{
	/** 이미지들과 폰트, 사운드들을 관리하는 매니져 클래스입니다. */
	class AssetManager
	{
	public:
		/** 생성자 함수를 정의해줍니다. */
		AssetManager() {}
		/** 소멸자 함수를 정의해줍니다. */
		~AssetManager() {}

		/**
		map 컨테이너에서 키를 이용해 텍스쳐를 로드해서 저장해줍니다.
		_textures map 컨테이너에 name을 키로 해서 texture를 추가해주는 함수의 원형을 선언합니다.
		구현부에서 구현해 주어야 합니다.
		*/
		void LoadTexture(string name, string fileName);

		/**
		왜 포인터 변수로 반환하지 않고 참조자로 반환할까요?
		참조자는 C언어 때는 없었습니다.
		C++에서 추가된 문법입니다.
		C++에서 포인터와 참조자는 비슷한데, 왜 참조자를 많이 쓸까요?
		포인터는 대상을 바꿀 수가 있습니다. 메모리 관리가 복잡해 질 수 있습니다. 
		참조자는 대상에 대한 별칭을 한 번 지정해주면 대상을 바꾸지 못합니다.
		메모리 관리가 편해집니다. 
		*/
		/**
		map 컨테이너에서 필요한 텍스쳐를 가져옵니다.
		_textures map 컨테이너에서 name을 키로 value값인 texture를 반환하는 함수의 원형을 선언합니다.
		*/
		sf::Texture& GetTexture(string name);

		/**
		에셋에서 폰트를 로드해서 _fonts map 컨테이너에 저장하는 함수입니다.
		map 컨테이너에 폰트 에셋을 로드해서 저장해줍니다.
		_fonts map 컨테이너에 name을 키로 해서 font를 추가해주는 함수의 원형을 선언합니다.
		*/
		void LoadFont(string name, string fileName);

		/**
		map 컨테이너에서 키로 필요한 폰트를 가져옵니다.
		_fonts map 컨테이너에서 name을 키로 value값이 font를 반환하는 함수의 원형을 선언합니다.
		*/
		sf::Font& GetFont(string name);

	private:
		/**
		왜 vector컨테이너를 쓰지 않고 map 컨테이너를 쓸까요?
		vector컨테이너에 저장을 하면 원하는 값을 가져오기 위해서는 반복문으로 조건검사를 해야합니다.
		map 컨테이너는 키값만 알면 반복문을 통하지 않고도 원하는 값을 가져올 수 있습니다.

		vector 컨테이너에 저장되어 있는 값들 중에서 원하는 값을 가져오기 위해서는 반복문을 통하지 않고
		LinQ 구문을 이용하면 됩니다. 아쉽게도 LinQ는 외부 라이브러리입니다.
		*/
		/** Texture들을 저장해둘 map 컨테이너 타입의 변수를 선언합니다. */
		map<string, sf::Texture> _textures;
		/** Font들을 저장해둘 map 컨테이너 타입의 변수를 선언합니다. */
		map<string, sf::Font> _fonts;
	};
}

