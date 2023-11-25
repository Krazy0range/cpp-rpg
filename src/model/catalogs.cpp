#include "catalogs.hpp"

const BlockItem *BlockItemCatalog::air = new BlockItem(
    LingualString("Air"),
    LingualString("An empty space of void."),
    "blocks/air.bmp",
    COMMON,
    BlockItem::MaxStackSize,
    0
);

const BlockItem *BlockItemCatalog::dirt = new BlockItem(
    LingualString("Dirt"),
    LingualString("A block of dust gathered over the centuries."),
    "blocks/dirt.bmp",
    COMMON,
    BlockItem::MaxStackSize,
    1
);

const BlockItem *BlockItemCatalog::cobblestone = new BlockItem(
    LingualString("Cobblestone"),
    LingualString("A block of broken stone."),
    "blocks/cobblestone.bmp",
    COMMON,
    BlockItem::MaxStackSize,
    2
);

const BlockItem *BlockItemCatalog::grass = new BlockItem(
    LingualString("Grass"),
    LingualString("A block of grass."),
    "blocks/grass.bmp",
    COMMON,
    BlockItem::MaxStackSize,
    3
);

const BlockItem *BlockItemCatalog::stone = new BlockItem(
    LingualString("Stone"),
    LingualString("A block of stone."),
    "blocks/stone.bmp",
    COMMON,
    BlockItem::MaxStackSize,
    4
);