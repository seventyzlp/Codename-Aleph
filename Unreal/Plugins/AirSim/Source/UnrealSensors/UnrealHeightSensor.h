#pragma once

#include "NedTransform.h"
#include "common/AirSimSettings.hpp"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "sensors/height/HeightSimple.hpp"




class UnrealHeightSensor : public msr::airlib::HeightSimple
{
public:
    typedef msr::airlib::AirSimSettings AirSimSettings;
	
    UnrealHeightSensor(const AirSimSettings::HeightSetting& setting,
                                              AActor* actor, const NedTransform* ned_transform);
	
    virtual float getHeight() override;
	
private:
    AActor* actor_;
    const NedTransform* ned_transform_;
    float heightvalue_;

    AActor* HeightSensor;
    FDoubleProperty* HeightProperty;
};
