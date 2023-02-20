/* SPDX-License-Identifier: GPL-2.0-or-later */

/** \file
 * \ingroup edasset
 */

#pragma once

#include <optional>
#include <string>

#include "BLI_function_ref.hh"

struct AssetHandle;
struct AssetLibraryReference;

namespace blender::asset_system {
class AssetLibrary;
}

/**
 * Get the asset library being read into an asset-list and identified using \a library_reference.
 *
 * \note The asset library may be allocated and loaded asynchronously, so it's not available right
 *       after fetching, and this function will return null. The asset list code sends `NC_ASSET |
 *       ND_ASSET_LIST_READING` notifiers until loading is done, they can be used to continuously
 *       call this function to retrieve the asset library once available.
 */
blender::asset_system::AssetLibrary *ED_assetlist_library_get_once_available(
    const AssetLibraryReference &library_reference);

AssetHandle *ED_assetlist_asset_get_from_index(const AssetLibraryReference *library_reference,
                                               int index);

/* Can return false to stop iterating. */
using AssetListIterFn = blender::FunctionRef<bool(AssetHandle &)>;
/**
 * Iterate the currently loaded assets for the referenced asset library, calling \a fn for each
 * asset. This may be executed while the asset list is loading asynchronously. Assets will then be
 * included as they get done loading.
 */
void ED_assetlist_iterate(const AssetLibraryReference &library_reference, AssetListIterFn fn);
