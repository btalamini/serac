# Copyright (c) 2019-2022, Lawrence Livermore National Security, LLC and
# other Serac Project Developers. See the top-level LICENSE file for
# details.
#
# SPDX-License-Identifier: (BSD-3-Clause)

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()

set(coefficients_sources
    sensitivity_coefficients.cpp
    loading_functions.cpp
    )

set(coefficients_headers
    sensitivity_coefficients.hpp
    loading_functions.hpp
    coefficient_extensions.hpp
    )

blt_add_library(
    NAME        serac_coefficients
    SOURCES     ${coefficients_sources}
    HEADERS     ${coefficients_headers}
    DEPENDS_ON  serac_numerics serac_state serac_physics_materials
    )

install(FILES ${coefficients_headers} DESTINATION include/serac/physics/coefficients )

install(TARGETS              serac_coefficients
        EXPORT               serac-targets
        DESTINATION          lib
        )
