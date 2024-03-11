#pragma once

#include "NedTransform.h"
#include "common/AirSimSettings.hpp"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "sensors/fume/FumeSimple.hpp"



class UnrealFumeSensor : public msr::airlib::FumeSimple
{
public:
    typedef msr::airlib::AirSimSettings AirSimSettings;
	
    UnrealFumeSensor(const AirSimSettings::FumeSetting& setting,
                                              AActor* actor, const NedTransform* ned_transform);
	
    virtual float getFume() override;
	
private:
    AActor* actor_;
    const NedTransform* ned_transform_;
    float fumevalue_;

    AActor* FumeSensor;
    FDoubleProperty* FumeProperty;
};
