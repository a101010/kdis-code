// GenTestData
// Generates header files to be used for regression
// test in unit tests. These header files must be
// manually copied into the source tree.
//
// Advice for maintainers:
// Set data in patterns that can detect problems in
// endianness conversion. A good rule of thumb:
// Each byte should be unique from all other bytes
// involved in an endianness conversion. For example,
// when writing a KUINT32 to the buffer, all four
// bytes should be distinct from each other.

#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <iostream>
#include "./WriteStreamAsHeader.hpp"


// Enum files that for some reason have to be explicitly
// specified on Solaris but not Linux
#include "KDIS/DataTypes/Enums/KDISEnums.h"
#include "KDIS/DataTypes/Enums/EnumInformationOperations.h"
#include "KDIS/DataTypes/Enums/EnumBurstDescriptor.h"

// DIS 5 DataTypes
#include "KDIS/DataTypes/AntennaLocation.h"
#include "KDIS/DataTypes/ArticulatedPart.h"
#include "KDIS/DataTypes/AttachedPart.h"
#include "KDIS/DataTypes/ClockTime.h"
#include "KDIS/DataTypes/CryptoSystem.h"
#include "KDIS/DataTypes/DeadReckoningParameter.h"
#include "KDIS/DataTypes/Descriptor.h"
#include "KDIS/DataTypes/EmissionSystem.h"
#include "KDIS/DataTypes/EmitterBeam.h"
#include "KDIS/DataTypes/EmitterSystem.h"
#include "KDIS/DataTypes/EncodingScheme.h"
#include "KDIS/DataTypes/EntityAppearance.h"
#include "KDIS/DataTypes/EntityCapabilities.h"
#include "KDIS/DataTypes/EntityIdentifier.h"
#include "KDIS/DataTypes/EntityMarking.h"
#include "KDIS/DataTypes/EntityType.h"
#include "KDIS/DataTypes/EulerAngles.h"
#include "KDIS/DataTypes/FixedDatum.h"
#include "KDIS/DataTypes/FundamentalParameterData.h"
#include "KDIS/DataTypes/ModulationType.h"
#include "KDIS/DataTypes/MunitionDescriptor.h"
#include "KDIS/DataTypes/RadioEntityType.h"
#include "KDIS/DataTypes/SimulationIdentifier.h"
#include "KDIS/DataTypes/Supplies.h"
#include "KDIS/DataTypes/TimeStamp.h"
#include "KDIS/DataTypes/TrackJamTargetIdentifier.h"
#include "KDIS/DataTypes/VariableDatum.h"
#include "KDIS/DataTypes/VariableParameter.h"
#include "KDIS/DataTypes/Vector.h"
#include "KDIS/DataTypes/WorldCoordinates.h"

// DIS 6 DataTypes
#include "KDIS/DataTypes/AcousticEmitterSystem.h"
#include "KDIS/DataTypes/AggregateIdentifier.h"
#include "KDIS/DataTypes/AggregateMarking.h"
#include "KDIS/DataTypes/AggregateType.h"
#include "KDIS/DataTypes/APA.h"
#include "KDIS/DataTypes/ArealObjectAppearance.h"
#include "KDIS/DataTypes/BeamData.h"
#include "KDIS/DataTypes/BoundingSphereRecord.h"
#include "KDIS/DataTypes/COMBICState.h"
#include "KDIS/DataTypes/CommunicationsChannelType.h"
#include "KDIS/DataTypes/ConeRecord1.h"
#include "KDIS/DataTypes/ConeRecord2.h"
#include "KDIS/DataTypes/EllipsoidRecord1.h"
#include "KDIS/DataTypes/EllipsoidRecord2.h"
#include "KDIS/DataTypes/EntityDestinationRecord.h"
#include "KDIS/DataTypes/EnvironmentType.h"
#include "KDIS/DataTypes/FlareState.h"
#include "KDIS/DataTypes/FundamentalOperationalData.h"
#include "KDIS/DataTypes/GaussianPlumeRecord.h"
#include "KDIS/DataTypes/GaussianPuffRecord.h"
#include "KDIS/DataTypes/GED_BasicFixedWingAircraft.h"
#include "KDIS/DataTypes/GED_BasicGroundCombatSoldier.h"
#include "KDIS/DataTypes/GED_BasicGroundCombatVehicle.h"
#include "KDIS/DataTypes/GED_BasicRotorWingAircraft.h"
#include "KDIS/DataTypes/GED_EnhancedFixedWingAircraft.h"
#include "KDIS/DataTypes/GED_EnhancedGroundCombatSoldier.h"
#include "KDIS/DataTypes/GED_EnhancedGroundCombatVehicle.h"
#include "KDIS/DataTypes/GED_EnhancedRotaryWingAircraft.h"
#include "KDIS/DataTypes/GED_GroundLogisticsVehicle.h"
#include "KDIS/DataTypes/GridAxisIrregular.h"
#include "KDIS/DataTypes/GridAxisRegular.h"
#include "KDIS/DataTypes/GridDataType0.h"
#include "KDIS/DataTypes/GridDataType1.h"
#include "KDIS/DataTypes/GridDataType2.h"
#include "KDIS/DataTypes/GroupAssignmentRecord.h"
#include "KDIS/DataTypes/GroupDestinationRecord.h"
#include "KDIS/DataTypes/IFF_ATC_NAVAIDS_FundamentalParameterData.h"
#include "KDIS/DataTypes/IFF_Layer2.h"
#include "KDIS/DataTypes/IntercomCommunicationParameters.h"
#include "KDIS/DataTypes/LayerHeader.h"
#include "KDIS/DataTypes/LE_DeadReckoningParameter.h"
#include "KDIS/DataTypes/LE_EntityIdentifier.h"
#include "KDIS/DataTypes/LE_EulerAngles.h"
#include "KDIS/DataTypes/LinearObjectAppearance.h"
#include "KDIS/DataTypes/LinearSegmentParameter.h"
#include "KDIS/DataTypes/LineRecord1.h"
#include "KDIS/DataTypes/LineRecord2.h"
#include "KDIS/DataTypes/MinefieldAppearance.h"
#include "KDIS/DataTypes/MinefieldDataFilter.h"
#include "KDIS/DataTypes/MineFusing.h"
#include "KDIS/DataTypes/MinePaintScheme.h"
#include "KDIS/DataTypes/NamedLocationIdentifier.h"
#include "KDIS/DataTypes/ObjectAppearance.h"
#include "KDIS/DataTypes/ObjectType.h"
#include "KDIS/DataTypes/OrientationError.h"
#include "KDIS/DataTypes/PerimeterPointCoordinate.h"
#include "KDIS/DataTypes/PointObjectAppearance.h"
#include "KDIS/DataTypes/PointRecord1.h"
#include "KDIS/DataTypes/PointRecord2.h"
#include "KDIS/DataTypes/PositionError.h"
#include "KDIS/DataTypes/PropulsionSystem.h"
#include "KDIS/DataTypes/RecordSet.h"
#include "KDIS/DataTypes/RectangularVolumeRecord1.h"
#include "KDIS/DataTypes/RectangularVolumeRecord2.h"
#include "KDIS/DataTypes/RectangularVolumeRecord3.h"
#include "KDIS/DataTypes/RelationshipRecord.h"
#include "KDIS/DataTypes/RelativeWorldCoordinates.h"
#include "KDIS/DataTypes/SecondaryOperationalData.h"
#include "KDIS/DataTypes/Shaft.h"
#include "KDIS/DataTypes/SilentAggregateSystem.h"
#include "KDIS/DataTypes/SilentEntitySystem.h"
#include "KDIS/DataTypes/SphereRecord1.h"
#include "KDIS/DataTypes/SphereRecord2.h"
#include "KDIS/DataTypes/SystemIdentifier.h"
#include "KDIS/DataTypes/UnderwaterAcousticEmitterBeam.h"
#include "KDIS/DataTypes/UnderwaterAcousticEmitterSystem.h"
#include "KDIS/DataTypes/UnderwaterAcousticFundamentalParameterData.h"
#include "KDIS/DataTypes/VectoringNozzleSystem.h"


// DIS 7 DataTypes
// TODO The problems below may be because I'm building with DIS_VERSION 6...
//      Might have other problems if I build with DIS_VERSION 5.
#include "KDIS/DataTypes/AttributeRecordSet.h"
#include "KDIS/DataTypes/CommunicationsNodeID.h"
#include "KDIS/DataTypes/DEAreaAimpoint.h"
#include "KDIS/DataTypes/EnhancedMode1Code.h"
//#include "KDIS/DataTypes/ExplosionDescriptor.h" // TODO for some reason on solaris some enum includes are not properly working
#include "KDIS/DataTypes/IFF_Layer3.h"
//#include "KDIS/DataTypes/IFF_Layer3Interrogator.h" // TODO for some reason on solaris some enum includes are not properly working
//#include "KDIS/DataTypes/IFF_Layer3Transponder.h" // TODO for some reason on solaris some enum includes are not properly working
#include "KDIS/DataTypes/IOCommunicationsNode.h"
#include "KDIS/DataTypes/IOEffect.h"
//#include "KDIS/DataTypes/Mode5InterrogatorBasicData.h" // TODO for some reason on solaris some enum includes are not properly working
//#include "KDIS/DataTypes/Mode5InterrogatorStatus.h" // TODO for some reason on solaris some enum includes are not properly working
//#include "KDIS/DataTypes/Mode5TransponderBasicData.h" // TODO for some reason on solaris some enum includes are not properly working
//#include "KDIS/DataTypes/Mode5TransponderStatus.h" // TODO for some reason on solaris some enum includes are not properly working
#include "KDIS/DataTypes/Mode5TransponderSupplementalData.h"
#include "KDIS/DataTypes/ModeXCodeRecord.h"
#include "KDIS/DataTypes/StandardVariable.h"

// DIS 5 PDUs
#include "KDIS/PDU/Distributed_Emission_Regeneration/Designator_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/Electromagnetic_Emission_PDU.h"

#include "KDIS/PDU/Entity_Info_Interaction/Collision_PDU.h"
#include "KDIS/PDU/Entity_Info_Interaction/Entity_State_PDU.h"

#include "KDIS/PDU/Logistics/Repair_Complete_PDU.h"
#include "KDIS/PDU/Logistics/Repair_Response_PDU.h"
#include "KDIS/PDU/Logistics/Resupply_Cancel_PDU.h"
#include "KDIS/PDU/Logistics/Resupply_Offer_PDU.h"
#include "KDIS/PDU/Logistics/Resupply_Received_PDU.h"
#include "KDIS/PDU/Logistics/Service_Request_PDU.h"

#include "KDIS/PDU/Radio_Communications/Receiver_PDU.h"
#include "KDIS/PDU/Radio_Communications/Signal_PDU.h"
#include "KDIS/PDU/Radio_Communications/Transmitter_PDU.h"

#include "KDIS/PDU/Simulation_Management/Acknowledge_PDU.h"
#include "KDIS/PDU/Simulation_Management/Action_Request_PDU.h"
#include "KDIS/PDU/Simulation_Management/Action_Response_PDU.h"
#include "KDIS/PDU/Simulation_Management/Comment_PDU.h"
#include "KDIS/PDU/Simulation_Management/Create_Entity_PDU.h"
#include "KDIS/PDU/Simulation_Management/Data_PDU.h"
#include "KDIS/PDU/Simulation_Management/Data_Query_PDU.h"
#include "KDIS/PDU/Simulation_Management/Event_Report_PDU.h"
#include "KDIS/PDU/Simulation_Management/Remove_Entity_PDU.h"
#include "KDIS/PDU/Simulation_Management/Set_Data_PDU.h"
#include "KDIS/PDU/Simulation_Management/Start_Resume_PDU.h"
#include "KDIS/PDU/Simulation_Management/Stop_Freeze_PDU.h"

#include "KDIS/PDU/Warfare/Detonation_PDU.h"
#include "KDIS/PDU/Warfare/Fire_PDU.h"

// DIS 6 PDUs
#include "KDIS/PDU/Distributed_Emission_Regeneration/IFF_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/SEES_PDU.h"
#include "KDIS/PDU/Distributed_Emission_Regeneration/Underwater_Acoustic_PDU.h"

#include "KDIS/PDU/Entity_Info_Interaction/Collision_Elastic_PDU.h"
#include "KDIS/PDU/Entity_Info_Interaction/Entity_State_Update_PDU.h"

#include "KDIS/PDU/Entity_Management/Aggregate_State_PDU.h"
#include "KDIS/PDU/Entity_Management/IsGroupOf_PDU.h"
#include "KDIS/PDU/Entity_Management/IsPartOf_PDU.h"
#include "KDIS/PDU/Entity_Management/Transfer_Control_Request_PDU.h"

#include "KDIS/PDU/Live_Entity/Appearance_PDU.h"
#include "KDIS/PDU/Live_Entity/Articulated_Parts_PDU.h"
#include "KDIS/PDU/Live_Entity/LE_Detonation_PDU.h"
#include "KDIS/PDU/Live_Entity/LE_Fire_PDU.h"
#include "KDIS/PDU/Live_Entity/TSPI_PDU.h"

#include "KDIS/PDU/Radio_Communications/Intercom_Control_PDU.h"
#include "KDIS/PDU/Radio_Communications/Intercom_Signal_PDU.h"

#include "KDIS/PDU/Simulation_Management_With_Reliability/Acknowledge_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Action_Request_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Action_Response_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Comment_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Create_Entity_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Data_Query_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Data_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Event_Report_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Record_Query_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Record_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Remove_Entity_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Set_Data_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Set_Record_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Start_Resume_R_PDU.h"
#include "KDIS/PDU/Simulation_Management_With_Reliability/Stop_Freeze_R_PDU.h"

#include "KDIS/PDU/Synthetic_Environment/Areal_Object_State_PDU.h"
#include "KDIS/PDU/Synthetic_Environment/Environmental_Process_PDU.h"
#include "KDIS/PDU/Synthetic_Environment/Gridded_Data_PDU.h"
#include "KDIS/PDU/Synthetic_Environment/Linear_Object_State_PDU.h"
#include "KDIS/PDU/Synthetic_Environment/Point_Object_State_PDU.h"

// DIS 7 PDUs
//#include "KDIS/PDU/Entity_Info_Interaction/Attribute_PDU.h"
//#include "KDIS/PDU/Information_Operations/IO_Action_PDU.h"
//#include "KDIS/PDU/Information_Operations/IO_Report_PDU.h"


using namespace KDIS;
using namespace DATA_TYPE;
using namespace PDU;
using namespace std;

#if defined(_WIN32)
    #define _access access
    #include <windows.h>
#else
    #include <unistd.h>
#endif

int main() {
    const string TEST_DATA_PATH = "./TestData";

    if(0 !=  access(TEST_DATA_PATH.c_str(), 0) ) {
        int err = 0;
        errno = 0;
    #if defined(_WIN32)
        err = _mkdir(TEST_DATA_PATH.c_str());
    #else
        mode_t mode = 0733;
        err = mkdir(TEST_DATA_PATH.c_str(), mode);
    #endif
        if(err != 0) {
            cerr << "could not create directory: " << TEST_DATA_PATH;
            cerr << " : " << strerror(errno) << endl;
            exit(EXIT_FAILURE);
        }
    }

    {
        APA dtIn = APA();
        dtIn.SetAPPI(KDIS::DATA_TYPE::ENUMS::GrahamsMKVCoffeeMaker);
        dtIn.SetStatus(false, true);
        KDataStream stream = dtIn.Encode();
        WriteStreamAsHeader("APAData", stream);
    }


    {
        ArealObjectAppearance dtIn = ArealObjectAppearance();
        // ObjectAppearance
        dtIn.SetPercentageComplete(75);
        dtIn.SetDamage(KDIS::DATA_TYPE::ENUMS::ObjectDamaged);
        dtIn.SetPredistributed(true);
        dtIn.SetState(true);
        dtIn.SetSmoking(true);
        dtIn.SetFlaming(false);
        // ArealObjectAppearance
        dtIn.SetBreach(KDIS::DATA_TYPE::ENUMS::Cleared2bit);
        dtIn.SetMineCount(0xFEED);
        KDataStream stream = dtIn.Encode();
        WriteStreamAsHeader("ArealObjectAppearanceData", stream);
    }

    {
        LinearObjectAppearance dtIn = LinearObjectAppearance();
        // ObjectAppearance
        dtIn.SetPercentageComplete(75);
        dtIn.SetDamage(KDIS::DATA_TYPE::ENUMS::ObjectDamaged);
        dtIn.SetPredistributed(true);
        dtIn.SetState(true);
        dtIn.SetSmoking(true);
        dtIn.SetFlaming(false);
        // LinearObjectAppearance
        dtIn.SetOpacity(50);
        dtIn.SetAttached(true);
        dtIn.SetBreachLength(0xFE);
        dtIn.SetBreachLocation(0xED);
        KDataStream stream = dtIn.Encode();
        WriteStreamAsHeader("LinearObjectAppearanceData", stream);
    }

    return EXIT_SUCCESS;
}

