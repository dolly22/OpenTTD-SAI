/* $Id: newgrf_canal.h 21890 2011-01-22 14:52:20Z rubidium $ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file newgrf_canal.h Handling of NewGRF canals. */

#ifndef NEWGRF_CANAL_H
#define NEWGRF_CANAL_H

#include "gfx_type.h"
#include "tile_type.h"
#include "newgrf_generic.h"

/**
 * List of different canal 'features'.
 * Each feature gets an entry in the canal spritegroup table
 */
enum CanalFeature {
	CF_WATERSLOPE,
	CF_LOCKS,
	CF_DIKES,
	CF_ICON,
	CF_DOCKS,
	CF_RIVER_SLOPE,
	CF_RIVER_EDGE,
	CF_END,
};

/** Flags controlling the display of canals. */
enum CanalFeatureFlag {
	CFF_HAS_FLAT_SPRITE = 0, ///< Additional flat ground sprite in the beginning.
};

/** Information about a water feature. */
struct WaterFeature {
	const SpriteGroup *group; ///< Sprite group to start resolving.
	const GRFFile *grffile;   ///< NewGRF where 'group' belongs to.
	uint8 callback_mask;      ///< Bitmask of canal callbacks that have to be called.
	uint8 flags;              ///< Flags controlling display.
};


/** Table of canal 'feature' sprite groups */
extern WaterFeature _water_feature[CF_END];


SpriteID GetCanalSprite(CanalFeature feature, TileIndex tile);

uint GetCanalSpriteOffset(CanalFeature feature, TileIndex tile, uint cur_offset);

#endif /* NEWGRF_CANAL_H */
