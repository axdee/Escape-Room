#pragma once
#include<SFML/System/Time.hpp>

namespace Engine {

	class state {
	public:
		state() {};
		virtual ~state() {};

		virtual void Init() = 0;
		virtual void ProcessInput() = 0;
		virtual void Update(sf::Time deltatime) = 0; 
		virtual void Draw() = 0;

		virtual void Pause() {};
		virtual void Start() {};
	};

}