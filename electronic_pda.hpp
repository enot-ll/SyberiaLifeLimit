class ItemPDA: Clothing
{
    scope = 2;
    title = "#pda_item_name";
    displayName = "#pda_item_name";
    descriptionShort = "#pda_item_desc";
    model="SyberiaLifeLimit\data\pda\gear_pda_g.p3d";
    inventorySlot = "Armband";
    itemInfo[] = {"Clothing","Armband"};
    rotationFlags = 34;
    weight = 210;
    heatIsolation = 0.1;
    absorbency = 0;
    repairableWithKits[] = {5,2};
    repairCosts[] = {30,25};
    itemSize[]={1,2};
    animClass="ItemPDA";
    oldpower=0;
    class ClothingTypes
    {
        male = "SyberiaLifeLimit\data\pda\gear_pda_m.p3d";
        female = "SyberiaLifeLimit\data\pda\gear_pda_m.p3d";
    };
    hiddenSelections[]=
    {
        "screen"
    };
    hiddenSelectionsTextures[]=
    {
        "SyberiaLifeLimit\data\pda\ekraan_bc.paa",
        "SyberiaLifeLimit\data\pda\ekraan_ok_co.paa"
    };
    attachments[]=
    {
        "BatteryD"
    };
    class EnergyManager
    {
        hasIcon=1;
        autoSwitchOff=1;
        energyUsagePerSecond=0.0001;
        plugType=1;
        attachmentAction=1;
        wetnessExposure=0.1;
    };
    ITEM_DAMAGE_SYSTEM(100, "SyberiaLifeLimit\data\pda\pda.rvmat", "SyberiaLifeLimit\data\pda\pda.rvmat", "SyberiaLifeLimit\data\pda\pda.rvmat");
    class AnimEvents
    {
        class SoundWeapon
        {
            class pickUpItem
            {
                soundSet = "Shirt_pickup_SoundSet";
                id = 797;
            };
            class drop
            {
                soundset = "Shirt_drop_SoundSet";
                id = 898;
            };
        };
    };
};