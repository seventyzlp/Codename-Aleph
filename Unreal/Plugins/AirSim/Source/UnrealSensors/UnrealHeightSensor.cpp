#include "UnrealHeightSensor.h"

float UnrealHeightSensor::getHeight()
{
    heightvalue_ = HeightProperty->GetPropertyValue_InContainer(HeightSensor);
    return heightvalue_;
}

UnrealHeightSensor::UnrealHeightSensor(const AirSimSettings::HeightSetting& setting, AActor* actor, const NedTransform* ned_transform)
    : HeightSimple(setting),actor_(actor),ned_transform_(ned_transform)
{
    TArray<AActor*> HeightSensors; 
    UWorld* pos = actor_->GetWorld();   //actor is flying pawn
    UGameplayStatics::GetAllActorsWithTag(pos, TEXT("HeightSensor"), HeightSensors); // get actor from tag

    HeightSensor = HeightSensors[0];
    HeightProperty = FindFieldChecked<FDoubleProperty>(HeightSensor->GetClass(), "Height"); // imposible to refresh the actor when update
    heightvalue_ = HeightProperty->GetPropertyValue_InContainer(HeightSensor);
    
}
