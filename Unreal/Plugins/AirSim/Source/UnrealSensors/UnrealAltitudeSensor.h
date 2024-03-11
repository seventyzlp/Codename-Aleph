#pragma once

#include "NedTransform.h"
#include "common/AirSimSettings.hpp"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "sensors/altitude/AltitudeSimple.hpp"



class UnrealAltitudeSensor : public msr::airlib::AltitudeSimple
{
public:
    typedef msr::airlib::AirSimSettings AirSimSettings;
	
    UnrealAltitudeSensor(const AirSimSettings::AltitudeSetting& setting,
                                              AActor* actor, const NedTransform* ned_transform);
	
    virtual float getAltitude() override;
	
private:
    AActor* actor_;
    const NedTransform* ned_transform_;
    float altitudevalue_;

    AActor* AltitudeSensor;
    FDoubleProperty* AltitudeProperty;
};
