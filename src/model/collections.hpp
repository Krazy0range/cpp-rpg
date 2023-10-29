#ifndef collections_hpp
#define collections_hpp

class PlayerCollections
{
    private:
        PlayerCollectionCombat  combat;
        PlayerCollectionMining  mining;
        PlayerCollectionFarming farming;
        PlayerCollectionFishing fishing;
        PlayerCollectionMagic   magic;
        PlayerCollectionTaming  taming;
};

class PlayerCollection
{

};

class PlayerCollectionCombat:   public PlayerCollection
{

};

class PlayerCollectionMining:   public PlayerCollection
{

};

class PlayerCollectionFarming:  public PlayerCollection
{

};

class PlayerCollectionFishing:  public PlayerCollection
{

};

class PlayerCollectionMagic:    public PlayerCollection
{

};

class PlayerCollectionTaming:   public PlayerCollection
{

};

#endif