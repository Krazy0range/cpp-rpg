#ifndef collections_hpp
#define collections_hpp

class Collection
{

};

class CollectionCombat:   public Collection
{

};

class CollectionMining:   public Collection
{

};

class CollectionFarming:  public Collection
{

};

class CollectionFishing:  public Collection
{

};

class CollectionMagic:    public Collection
{

};

class CollectionTaming:   public Collection
{

};

class Collections
{
    private:
        CollectionMining    mining;
        CollectionCombat    combat;
        CollectionFarming   farming;
        CollectionFishing   fishing;
        CollectionMagic     magic;
        CollectionTaming    taming;
};

#endif