// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#include "UnrealSensorFactory.h"

#include "UnrealAltitudeSensor.h"
#include "UnrealFumeSensor.h"
#include "UnrealHeightSensor.h"
#include "UnrealHumiditySensor.h"
#include "UnrealTemperatureSensor.h"
#include "UnrealSensors/UnrealLuminanceSensor.h"
#include "UnrealSensors/UnrealDistanceSensor.h"
#include "UnrealSensors/UnrealLidarSensor.h"

UnrealSensorFactory::UnrealSensorFactory(AActor* actor, const NedTransform* ned_transform)
{
    setActor(actor, ned_transform);
}

std::shared_ptr<msr::airlib::SensorBase> UnrealSensorFactory::createSensorFromSettings(
    const AirSimSettings::SensorSetting* sensor_setting) const
{
    using SensorBase = msr::airlib::SensorBase;

    switch (sensor_setting->sensor_type) {
    case SensorBase::SensorType::Distance:
        return std::shared_ptr<UnrealDistanceSensor>(new UnrealDistanceSensor(
            *static_cast<const AirSimSettings::DistanceSetting*>(sensor_setting), actor_, ned_transform_));
    case SensorBase::SensorType::Lidar:
        return std::shared_ptr<UnrealLidarSensor>(new UnrealLidarSensor(
            *static_cast<const AirSimSettings::LidarSetting*>(sensor_setting), actor_, ned_transform_));
    case SensorBase::SensorType::Luminance:
        return std::shared_ptr<UnrealLuminanceSensor>(new UnrealLuminanceSensor(
            *static_cast<const AirSimSettings::LuminanceSetting*>(sensor_setting), actor_, ned_transform_));
    case SensorBase::SensorType::Temperature:
        return std::shared_ptr<UnrealTemperatureSensor>(new UnrealTemperatureSensor(
            *static_cast<const AirSimSettings::TemperatureSetting*>(sensor_setting), actor_, ned_transform_));
    case SensorBase::SensorType::Humidity:
        return std::shared_ptr<UnrealHumiditySensor>(new UnrealHumiditySensor(
            *static_cast<const AirSimSettings::HumiditySetting*>(sensor_setting), actor_, ned_transform_));
    case SensorBase::SensorType::Height:
        return std::shared_ptr<UnrealHeightSensor>(new UnrealHeightSensor(
            *static_cast<const AirSimSettings::HeightSetting*>(sensor_setting), actor_, ned_transform_));
    case SensorBase::SensorType::Altitude:
        return std::shared_ptr<UnrealAltitudeSensor>(new UnrealAltitudeSensor(
            *static_cast<const AirSimSettings::AltitudeSetting*>(sensor_setting), actor_, ned_transform_));
    case SensorBase::SensorType::Fume:
        return std::shared_ptr<UnrealFumeSensor>(new UnrealFumeSensor(
            *static_cast<const AirSimSettings::FumeSetting*>(sensor_setting), actor_, ned_transform_));
        
    default:
        
        return msr::airlib::SensorFactory::createSensorFromSettings(sensor_setting);
    }
}

void UnrealSensorFactory::setActor(AActor* actor, const NedTransform* ned_transform)
{
    actor_ = actor;
    ned_transform_ = ned_transform;
}
