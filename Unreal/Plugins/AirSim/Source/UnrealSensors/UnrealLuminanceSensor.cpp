#include "UnrealLuminanceSensor.h"



float UnrealLuminanceSensor::getLuminance()
{
	// get luminance form actor detector
	luminancevalue_ = lumproperty->GetPropertyValue_InContainer(LuminanceCamera);
	return luminancevalue_;
}

UnrealLuminanceSensor::UnrealLuminanceSensor(const AirSimSettings::LuminanceSetting& setting,
						  AActor* actor, const NedTransform* ned_transform)
							  : LuminanceSimple(setting),actor_(actor),ned_transform_(ned_transform)
{
	TArray<AActor*> LuminanceCameras;
	UWorld* pos = actor_->GetWorld();
	UGameplayStatics::GetAllActorsWithTag(pos, TEXT("LuminanceSensor"), LuminanceCameras); // get actor from tag

	LuminanceCamera = LuminanceCameras[0];
	lumproperty = FindFieldChecked<FIntProperty>(LuminanceCamera->GetClass(), "Luminance"); // imposible to refresh the actor when update
	luminancevalue_ = lumproperty->GetPropertyValue_InContainer(LuminanceCamera);
}