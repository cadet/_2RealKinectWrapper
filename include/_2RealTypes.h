/*
	CADET - Center for Advances in Digital Entertainment Technologies
	Copyright 2011 University of Applied Science Salzburg / MultiMediaTechnology

	http://www.cadet.at
	http://multimediatechnology.at/

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

	Authors: Robert Praxmarer, Gerlinde Emsenhuber, Robert Sommeregger
	Email: support@cadet.at
	Created: 08-31-2011
*/
#pragma once
#include <stdint.h>
#include <vector>
#include "_2RealImageSource.h"


namespace _2Real
{
	struct _2RealVector3f;
	typedef std::vector<const _2RealVector3f>		_2RealPositionVector3f;
	typedef std::vector<const _2RealVector2f>		_2RealPositionVector2f;


	/*	_2RealJointType *
		Filtering specific joints out of joint vector with operator[]
	*/
	enum _2RealJointType
	{
		JOINT_HEAD					= 0,
		JOINT_NECK					= 1,
		JOINT_TORSO					= 2,
		JOINT_WAIST					= 3,		// currently not available for OPENNI

		JOINT_LEFT_COLLAR			= 4,		// currently not available for OPENNI; WSDK
		JOINT_LEFT_SHOULDER			= 5,
		JOINT_LEFT_ELBOW			= 6,
		JOINT_LEFT_WRIST			= 7,		// currently not available OPENNI
		JOINT_LEFT_HAND				= 8,
		JOINT_LEFT_FINGERTIP		= 9,		// currently not available for OPENNI; WSDK

		JOINT_RIGHT_COLLAR			= 10,		// currently not available for OPENNI; WSDK
		JOINT_RIGHT_SHOULDER		= 11,
		JOINT_RIGHT_ELBOW			= 12,
		JOINT_RIGHT_WRIST			= 13,		// currently not available for OPENNI
		JOINT_RIGHT_HAND			= 14,
		JOINT_RIGHT_FINGERTIP		= 15,		// currently not available for OPENNI; WSDK

		JOINT_LEFT_HIP				= 16,
		JOINT_LEFT_KNEE				= 17,
		JOINT_LEFT_ANKLE			= 18,		// currently not available for OPENNI
		JOINT_LEFT_FOOT				= 19,

		JOINT_RIGHT_HIP				= 20,
		JOINT_RIGHT_KNEE			= 21,
		JOINT_RIGHT_ANKLE			= 22,		//	currently not available for OPENNI
		JOINT_RIGHT_FOOT			= 23
	};


	/*	_2RealGenerator *
		For starting specific sensor capabilities and fetching specific sensor data
	*/
	enum _2RealGenerator
	{
		COLORIMAGE			= 1,
		DEPTHIMAGE			= 2,
		INFRAREDIMAGE		= 4,
		USERIMAGE			= 8,
		USERIMAGE_COLORED	= 16,
		CONFIG_DEFAULT		= 3
	};


	/*	_2RealImages *
		_2Real started with WSDK: if started with user generator, depth resolution
		only available in 320x240 or 80x60
		_2Real started with OpenNI: connected kinect -> no downsampling available!
		so there are only 640x320 images, Primesense sensor conn. -> downsampling
	*/
	enum _2RealImages
	{
		IMAGE_COLOR_1280X1024		= 1,		//WSDK
		IMAGE_COLOR_640X480			= 2,		//WSDK, OpenNI
		IMAGE_COLOR_320X240			= 4,		//WSDK
		IMAGE_USER_DEPTH_640X480	= 16,		//WSDK, OpenNI,	user image and depth image must have same resolution
		IMAGE_USER_DEPTH_320X240	= 32,		//WSDK,	user image and depth image must have same resolution
		IMAGE_USER_DEPTH_80X60		= 64,		//WSDK,	user image and depth image must have same resolution
		IMAGE_INFRARED_640X480		= 128,		//OpenNI
		IMAGE_INFRARED_320X240		= 256,		//OpenNI
		IMAGE_MIRRORING				= 512,
#ifndef TARGET_MSKINECTSDK
		IMAGE_CONFIG_DEFAULT		= 530 //IMAGE_COLOR_640X480, IMAGE_DEPTH_640X480, IMAGE_MIRRORING
#else
		IMAGE_CONFIG_DEFAULT		= 546 //IMAGE_COLOR_640X480, IMAGE_DEPTH_320X240, IMAGE_MIRRORING
#endif
		
	};
	
	// Logger enums
	enum _2RealLogLevel {none, error, warn, info, debug };	// debug outputs all messages, none outputs nothing

	struct _2RealVector3f
	{
		_2RealVector3f( void );
		_2RealVector3f( float X, float Y, float Z );
		_2RealVector3f( const _2RealVector3f& o );
		_2RealVector3f& operator=( const _2RealVector3f& o );


		float x;
		float y;
		float z;
	};

	
	struct _2RealMatrix3x3
	{
		float elements[9];
	};
}