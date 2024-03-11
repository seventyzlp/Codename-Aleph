#pragma once

#include "NedTransform.h"
#include "../../../../../AirLib/include/sensors/temperature/TemperatureSimple.hpp"
#include "common/AirSimSettings.hpp"
#include "GameFramework/Actor.h"
#include "sensors/temperature/TemperatureSimple.hpp"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"



class UnrealTemperatureSensor : public msr::airlib::TemperatureSimple
{
public:
    typedef msr::airlib::AirSimSettings AirSimSettings;

    UnrealTemperatureSensor(const AirSimSettings::TemperatureSetting &setting,
                          AActor* actor, const NedTransform* ned_transform);

    virtual float getTemperature() override;

private:
    AActor* actor_;
    const NedTransform* ned_transform_;
    float temperaturevalue_;

    AActor* TemperatureSensor;
    FDoubleProperty* TemperatureProperty;

};

