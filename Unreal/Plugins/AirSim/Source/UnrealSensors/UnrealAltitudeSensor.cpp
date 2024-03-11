#include "UnrealAltitudeSensor.h"

float UnrealAltitudeSensor::getAltitude()
{
    altitudevalue_ = AltitudeProperty->GetPropertyValue_InContainer(AltitudeSensor);
    return altitudevalue_;
}

UnrealAltitudeSensor::UnrealAltitudeSensor(const AirSimSettings::AltitudeSetting& setting, AActor* actor, const NedTransform* ned_transform)
    :AltitudeSimple(setting),actor_(actor),ned_transform_(ned_transform)
{
    TArray<AActor*> AltitudeSensors; 
    UWorld* pos = actor_->GetWorld();   //actor is flying pawn
    UGameplayStatics::GetAllActorsWithTag(pos, TEXT("AltitudeSensor"), AltitudeSensors); // get actor from tag

    AltitudeSensor = AltitudeSensors[0];
    AltitudeProperty = FindFieldChecked<FDoubleProperty>(AltitudeSensor->GetClass(), "Altitude"); // imposible to refresh the actor when update
    altitudevalue_ = AltitudeProperty->GetPropertyValue_InContainer(AltitudeSensor);
}
