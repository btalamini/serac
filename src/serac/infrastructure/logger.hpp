// Copyright (c) 2019-2022, Lawrence Livermore National Security, LLC and
// other Serac Project Developers. See the top-level LICENSE file for
// details.
//
// SPDX-License-Identifier: (BSD-3-Clause)

/**
 * @file logger.hpp
 *
 * @brief This file contains the all the necessary functions and macros required
 *        for logging as well as a helper function to exit the program gracefully.
 */

#pragma once

#include "axom/slic.hpp"
#include "axom/fmt.hpp"
#include "mpi.h"

// Logger functionality
namespace serac::logger {
/**
 * @brief Initializes and setups the logger.
 *
 * Setups and tailors the SLIC logger for Serac.  Sets the SLIC loggings streams
 * and tells SLIC how to format the messages.  This function also creates different
 * logging streams if you are running serial, parallel, or parallel with Lumberjack
 * support.
 *
 * @param[in] comm MPI communicator that the logger will use
 */
bool initialize(MPI_Comm comm);

/**
 * @brief Finalizes the logger.
 *
 * Closes and finalizes the SLIC logger.
 */
void finalize();

/**
 * @brief Flushes messages currently held by the logger.
 *
 * If running in parallel, SLIC doesn't output messages immediately.  This flushes
 * all messages currently held by SLIC.  This is a collective operation because
 * messages can be spread across MPI ranks.
 */
void flush();

/**
 * @brief Returns the rank of the current process obtained when the logger
 * was initialized, will be 0 if the logger was not initialized
 */
int rank();

}  // namespace serac::logger

// Utility SLIC macros

/**
 * @brief Macro that logs given error message only on rank 0.
 */
#define SLIC_ERROR_ROOT(msg) SLIC_ERROR_IF(serac::logger::rank() == 0, msg)

/**
 * @brief Macro that logs given warning message only on rank 0.
 */
#define SLIC_WARNING_ROOT(msg) SLIC_WARNING_IF(serac::logger::rank() == 0, msg)

/**
 * @brief Macro that logs given info message only on rank 0.
 */
#define SLIC_INFO_ROOT(msg) SLIC_INFO_IF(serac::logger::rank() == 0, msg)

/**
 * @brief Macro that logs given debug message only on rank 0.
 */
#define SLIC_DEBUG_ROOT(msg) SLIC_DEBUG_IF(serac::logger::rank() == 0, msg)

/**
 * @brief Macro that logs given error message only on rank 0 if EXP is true.
 */
#define SLIC_ERROR_ROOT_IF(EXP, msg) SLIC_ERROR_IF((EXP) && (serac::logger::rank() == 0), msg)

/**
 * @brief Macro that logs given warning message only on rank 0 if EXP is true.
 */
#define SLIC_WARNING_ROOT_IF(EXP, msg) SLIC_WARNING_IF((EXP) && (serac::logger::rank() == 0), msg)

/**
 * @brief Macro that logs given info message only on rank 0 if EXP is true.
 */
#define SLIC_INFO_ROOT_IF(EXP, msg) SLIC_INFO_IF((EXP) && (serac::logger::rank() == 0), msg)

/**
 * @brief Macro that logs given debug message only on rank 0 if EXP is true.
 */
#define SLIC_DEBUG_ROOT_IF(EXP, msg) SLIC_DEBUG_IF((EXP) && (serac::logger::rank() == 0), msg)
