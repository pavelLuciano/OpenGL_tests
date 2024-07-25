#include "Hexagon.h"

const float Hexagon::vertices[] = {
	//X   Y
	 0.0f  , 0.0f  ,
	 0.5f  , 0.0f  ,
	 0.25f , 0.433f,
	-0.25f , 0.433f,
	-0.5f  , 0.0f  ,
	-0.25f ,-0.433f,
	 0.25f ,-0.433f
};

const unsigned int Hexagon::indices[] = {
	0, 1, 2,
	0, 2, 3,
	0, 3, 4,
	0, 4, 5,
	0, 5, 6,
	0, 6, 1
};
