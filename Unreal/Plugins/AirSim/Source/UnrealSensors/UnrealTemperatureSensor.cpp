#include "UnrealTemperatureSensor.h"

float UnrealTemperatureSensor::getTemperature()
{
    temperaturevalue_ = TemperatureProperty->GetPropertyValue_InContainer(TemperatureSensor);
    return temperaturevalue_;
}

UnrealTemperatureSensor::UnrealTemperatureSensor(const AirSimSettings::TemperatureSetting& setting, AActor* actor, const NedTransform* ned_transform)
    :TemperatureSimple(setting),actor_(actor),ned_transform_(ned_transform)
{
    TArray<AActor*> TemperatureSensors; 
    UWorld* pos = actor_->GetWorld();   //actor is flying pawn
    UGameplayStatics::GetAllActorsWithTag(pos, TEXT("TemperatureSensor"), TemperatureSensors); // get actor from tag
    
    TemperatureSensor = TemperatureSensors[0]; //get sensor from index
    TemperatureProperty = FindFieldChecked<FDoubleProperty>(TemperatureSensor->GetClass(),"Temperature");
    temperaturevalue_ = TemperatureProperty->GetPropertyValue_InContainer(TemperatureSensor); 
} 
