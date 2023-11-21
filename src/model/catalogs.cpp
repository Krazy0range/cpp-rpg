#include "catalogs.hpp"

const BlockItem *BlockItemCatalog::cobblestone = new BlockItem(
    LingualString("Cobblestone"),
    LingualString("A block of broken stone."),
    "blocks/cobblestone",
    COMMON,
    BlockItem::MaxStackSize,
    0
);