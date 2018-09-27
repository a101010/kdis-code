#include <iostream>
#include "gtest/gtest.h"

#include "KDIS/DataTypes/AirPlatformAppearance.h"
#include "KDIS/DataTypes/LifeFormAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;

TEST(AppearanceAccess_Tests, AirPlatformAppearance)
{
    const KUINT32 DATA = 0x01234567;
    // For reference, the expected bit pattern:
    // Bit 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16
    //      0  0  0  0  0  0  0  1  0  0  1  0  0  0  1  1
    // Bit 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
    //      0  1  0  0  0  1  0  1  0  1  1  0  0  1  1  1

    // Initialize to zero
    AirPlatformAppearance dtIn = AirPlatformAppearance();
    KUINT32* dtIn_as_KUINT32_ptr = (KUINT32*) &dtIn;
    EXPECT_EQ(0, *dtIn_as_KUINT32_ptr);

    // Initialize with data
    *dtIn_as_KUINT32_ptr = DATA;

    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::Camouflage,
            dtIn.GetEntityPaintScheme());
    // TODO would IsEntityMobilityKilled be a more accurate name?
    EXPECT_TRUE(dtIn.DoesEntityMobilityKill());
    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::CovertLighting,
            dtIn.GetNVGMode());
    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::NoDamage,
            dtIn.GetEntityDamage());
    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::EngineSmokeAndSmokePlume,
            dtIn.GetEntitySmoke());
    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::Medium,
            dtIn.GetEntityTrailingEffect());
    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::PrimaryHatchIsPopped,
            dtIn.GetEntityCanopyState());
    EXPECT_FALSE(dtIn.IsEntityLandingLightsOn());
    EXPECT_FALSE(dtIn.IsEntityNavigationLightsOn());
    EXPECT_TRUE(dtIn.IsEntityAntiCollisionLightsOn());
    EXPECT_FALSE(dtIn.IsEntityFlaming());
    EXPECT_TRUE(dtIn.IsAfterburnerOn());
    EXPECT_TRUE(dtIn.IsEntityLowerAntiCollisionLightOn());
    EXPECT_FALSE(dtIn.IsEntityUpperAntiCollisionLightOn());
    EXPECT_FALSE(dtIn.GetAntiCollisionLightDayNight());
    EXPECT_FALSE(dtIn.IsBlinking());
    EXPECT_TRUE(dtIn.IsEntityFrozen());
    EXPECT_FALSE(dtIn.IsEntityPowerPlantOn());
    EXPECT_TRUE(dtIn.IsEntityStateActive());
    EXPECT_TRUE(dtIn.IsEntityFormationLightsOn());
    EXPECT_FALSE(dtIn.IsCargoDoorsOpened());
    EXPECT_FALSE(dtIn.GetNavigationPositionBrightness());
    EXPECT_FALSE(dtIn.IsEntitySpotLightsOn());
    EXPECT_FALSE(dtIn.IsEntityInteriorLightsOn());
    EXPECT_FALSE(dtIn.IsReverseThrustEngaged());
    EXPECT_FALSE(dtIn.IsWeightOnWheels());
}

TEST(AppearanceAccess_Tests, LifeFormAppearance)
{
    const KUINT32 DATA = 0x01234567;
    // For reference, the expected bit pattern:
    // Bit 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16
    //      0  0  0  0  0  0  0  1  0  0  1  0  0  0  1  1
    // Bit 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
    //      0  1  0  0  0  1  0  1  0  1  1  0  0  1  1  1

    // Initialize to zero
    LifeFormAppearance dtIn = LifeFormAppearance();
    KUINT32* dtIn_as_KUINT32_ptr = (KUINT32*) &dtIn;
    EXPECT_EQ(0, *dtIn_as_KUINT32_ptr);

    // Initialize with data
    *dtIn_as_KUINT32_ptr = DATA;

    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::Camouflage,
            dtIn.GetEntityPaintScheme());
    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::NoDamage,
            dtIn.GetEntityDamage());
    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::UsingNonLethalWeapon2,
            dtIn.GetEntityEntityCompliance());
    EXPECT_FALSE(dtIn.IsEntitySignalSmokeInUse());
    EXPECT_FALSE(dtIn.IsEntityFlashLightsOn());
    EXPECT_FALSE(dtIn.IsEntitySignalMirrorInUse());
    EXPECT_TRUE(dtIn.IsEntityIRStrobeOn());
    EXPECT_FALSE(dtIn.IsEntityIRIlluminatorOn());
    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::UprightRunning,
            dtIn.GetEntityLifeformState());
    EXPECT_TRUE(dtIn.IsEntityFrozen());
    EXPECT_FALSE(dtIn.IsEntityMountedHoisted());
    EXPECT_TRUE(dtIn.IsEntityStateActive());
    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::PrimaryWeaponIsStowed,
                dtIn.GetEntityLifeformWeapon1());
    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::NoPrimaryWeaponPresent,
            dtIn.GetEntityLifeformWeapon2());
    EXPECT_EQ(KDIS::DATA_TYPE::ENUMS::DesertCamouflage,
                dtIn.GetEntityCamouflage());
    EXPECT_FALSE(dtIn.IsConcealedStationary());
    EXPECT_FALSE(dtIn.IsConcealedMovement());
}
