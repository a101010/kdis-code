
ADD_SUBDIRECTORY(Bundle)
ADD_SUBDIRECTORY(Entity_State_PDU)
ADD_SUBDIRECTORY(PDU_Factory1)
ADD_SUBDIRECTORY(PDU_Factory2)

IF(DIS_VERSION GREATER 5)
	ADD_SUBDIRECTORY(Environmental_Process_PDU)
ENDIF(DIS_VERSION GREATER 5)
