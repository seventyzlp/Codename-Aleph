#include "UnrealHumiditySensor.h"

float UnrealHumiditySensor::getHumidity()
{
    humidityvalue_ = HumidityProperty->GetPropertyValue_InContainer(HumiditySensor);
    return humidityvalue_;
}

UnrealHumiditySensor::UnrealHumiditySensor(const AirSimSettings::HumiditySetting& setting, AActor* actor, const NedTransform* ned_transform)
    :HumiditySimple(setting),actor_(actor),ned_transform_(ned_transform)
{
    TArray<AActor*> HumiditySensors; 
    UWorld* pos = actor_->GetWorld();   //actor is flying pawn
    UGameplayStatics::GetAllActorsWithTag(pos, TEXT("HumiditySensor"), HumiditySensors); // get actor from tag

    HumiditySensor = HumiditySensors[0];
    HumidityProperty = FindFieldChecked<FDoubleProperty>(HumiditySensor->GetClass(), "Humidity"); // imposible to refresh the actor when update
    humidityvalue_ = HumidityProperty->GetPropertyValue_InContainer(HumiditySensor);
}
