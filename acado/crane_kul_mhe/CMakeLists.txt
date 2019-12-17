################################################################################
#
# Description:
#	Main build system script for the ACADO toolkit.
#
# Authors:
#	Joel Andersson
#	Attila Kozma
#	Milan Vukov, milan.vukov@esat.kuleuven.be
#
# Year:
#	2011 - 2014.
#
# Usage:
#	- Linux, OS X, Windows: more info can be found on www.acadotoolkit.org
#
################################################################################

################################################################################
#
# Project settings
#
################################################################################

#
# Minimum required version of cmake 
#
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

#
# Project name and programming languages used
#
PROJECT( MY_COOL_PROJECT CXX C )

#
# Project version information
#
# SET( ACADO_VERSION_MAJOR  1 )
# SET( ACADO_VERSION_MINOR  2 )
# SET( ACADO_VERSION_PATCH  2 )
# SET( ACADO_VERSION_STRING
# 		${ACADO_VERSION_MAJOR}.${ACADO_VERSION_MINOR}.${ACADO_VERSION_PATCH}beta
# )

#
# Folder path for generated executables
#
# SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

#
# Folder path for generated libraries
#
# SET( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib )

#
# CMake module(s) path
#
# SET( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake" )
SET( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/cmake")


################################################################################
#
# User configuration
#
################################################################################


################################################################################
#
# Dependencies
#
################################################################################

# FIND_PACKAGE( Doxygen )

FIND_PACKAGE( ACADO REQUIRED )

#
# Include directories
#
INCLUDE_DIRECTORIES( . ${ACADO_INCLUDE_DIRS} )

# ADD_DEFINITIONS( -std=c++11 )


################################################################################
#
# Compiler settings
#
################################################################################

# Suppressing some stupid warnings from CMake 3.0
IF (POLICY CMP0026)
	CMAKE_POLICY(SET CMP0026 OLD)
ENDIF( )
IF (POLICY CMP0042)
	CMAKE_POLICY(SET CMP0042 OLD)
ENDIF( )

#
# Compiler options are in separate file
#
# INCLUDE( CompilerOptions )

################################################################################
#
# Include directories
#
################################################################################

# INCLUDE_DIRECTORIES(
# 	${PROJECT_SOURCE_DIR}
# 	${PROJECT_SOURCE_DIR}/acado
# 	${PROJECT_SOURCE_DIR}/external_packages
# 	${PROJECT_SOURCE_DIR}/external_packages/qpOASES-3.2.0/include
# 	${PROJECT_BINARY_DIR}
# )

#
# Configure and install CMake package configuration file
#
# SET( ACADO_INSTALL_INCLUDE_DIRS
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_INCLUDE_DIR}
# )
# SET( ACADO_INSTALL_LIBRARY_DIRS
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_LIB_DIR}
# )
# SET( ACADO_INSTALL_EXTERNAL_PACKAGES_DIR
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages
# )
# SET( ACADO_INSTALL_CMAKE_DIR
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_CMAKE_DIR}
# )
# 
# IF ( ACADO_BUILD_STATIC )
# 	SET( ACADO_INSTALL_STATIC_LIBRARIES
# 		acado_toolkit
# 	)
# ENDIF()
# 
# IF ( ACADO_BUILD_SHARED )
# 	SET( ACADO_INSTALL_SHARED_LIBRARIES
# 		acado_toolkit_s
# 	)
# ENDIF()

# SET( ACADO_INSTALL_QPOASES_EMBEDDED_SOURCES
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/SRC/Bounds.cpp
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/SRC/CyclingManager.cpp 
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/SRC/MessageHandling.cpp
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/SRC/QProblem.cpp
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/SRC/Utils.cpp
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/SRC/Constraints.cpp
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/SRC/Indexlist.cpp	     
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/SRC/QProblemB.cpp
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/SRC/SubjectTo.cpp
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/SRC/EXTRAS/SolutionAnalysis.cpp
# )
# SET( ACADO_INSTALL_QPOASES_EMBEDDED_INC_DIRS
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/INCLUDE
# 	${CMAKE_INSTALL_PREFIX}/${INSTALL_DATA_DIR}/external_packages/qpoases/SRC
# )
################################################################################
#
# Build examples
#
################################################################################

# ADD_SUBDIRECTORY( examples )
INCLUDE( UseACADO )

# ADD_SUBDIRECTORY( mpc_mhe )
# ADD_SUBDIRECTORY( mhe )

ACADO_APPLICATION( code_generation_crane_kul_mhe crane_kul_mhe.cpp )

ACADO_GENERATE_COMPILE(
	# Target name
	code_generation_crane_kul_mhe
	# Code export folder name
	crane_kul_mhe_export
	# Test file source name
	crane_kul_mhe_test.cpp
)
