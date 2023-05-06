/* SPDX-License-Identifier: GPL-2.0-or-later
 * Copyright 2016 Blender Foundation */

/** \file
 * \ingroup edgizmolib
 */

#include "../gizmo_geometry.h"

static const float verts[][3] = {
    {1.000000, 1.000000, -1.000000},
    {1.000000, -1.000000, -1.000000},
    {-1.000000, -1.000000, -1.000000},
    {-1.000000, 1.000000, -1.000000},
    {1.000000, 1.000000, 1.000000},
    {0.999999, -1.000001, 1.000000},
    {-1.000000, -1.000000, 1.000000},
    {-1.000000, 1.000000, 1.000000},
};

static const float normals[][3] = {
    {0.577349, 0.577349, -0.577349},
    {0.577349, -0.577349, -0.577349},
    {-0.577349, -0.577349, -0.577349},
    {-0.577349, 0.577349, -0.577349},
    {0.577349, 0.577349, 0.577349},
    {0.577349, -0.577349, 0.577349},
    {-0.577349, -0.577349, 0.577349},
    {-0.577349, 0.577349, 0.577349},
};

static const ushort indices[] = {
    1, 2, 3, 7, 6, 5, 4, 5, 1, 5, 6, 2, 2, 6, 7, 0, 3, 7,
    0, 1, 3, 4, 7, 5, 0, 4, 1, 1, 5, 2, 3, 2, 7, 4, 0, 7,
};

GizmoGeomInfo wm_gizmo_geom_data_cube = {
    .nverts = 8,
    .ntris = 12,
    .verts = verts,
    .normals = normals,
    .indices = indices,
};
