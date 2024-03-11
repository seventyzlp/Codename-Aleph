#include "UnrealFumeSensor.h"

float UnrealFumeSensor::getFume()
{
    fumevalue_ = FumeProperty->GetPropertyValue_InContainer(FumeSensor);
    return fumevalue_;
}

UnrealFumeSensor::UnrealFumeSensor(const AirSimSettings::FumeSetting& setting, AActor* actor, const NedTransform* ned_transform)
                    : FumeSimple(setting),actor_(actor),ned_transform_(ned_transform)

{
    TArray<AActor*> FumeSensors; 
    UWorld* pos = actor_->GetWorld();   //actor is flying pawn
    UGameplayStatics::GetAllActorsWithTag(pos, TEXT("FumeSensor"), FumeSensors); // get actor from tag

    FumeSensor = FumeSensors[0];
    FumeProperty = FindFieldChecked<FDoubleProperty>(FumeSensor->GetClass(), "Fume"); // imposible to refresh the actor when update
    fumevalue_ = FumeProperty->GetPropertyValue_InContainer(FumeSensor);
    
}
