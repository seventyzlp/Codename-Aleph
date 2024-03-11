#pragma once

#include "NedTransform.h"
#include "common/AirSimSettings.hpp"
#include "GameFramework/Actor.h"
#include "sensors/luminance/LuminanceSimple.hpp"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Kismet/KismetRenderingLibrary.h"




class NedTransform;

class UnrealLuminanceSensor : public msr::airlib::LuminanceSimple
{
public:
	typedef msr::airlib::AirSimSettings AirSimSettings;
	
	UnrealLuminanceSensor(const AirSimSettings::LuminanceSetting& setting,
						  AActor* actor, const NedTransform* ned_transform);
	
	virtual float getLuminance() override;
	
private:
	AActor* actor_;
	const NedTransform* ned_transform_;
	float luminancevalue_;

	AActor* LuminanceCamera;
	FDoubleProperty* lumproperty;
};
