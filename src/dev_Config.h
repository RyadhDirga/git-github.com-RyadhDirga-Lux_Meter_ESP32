// MainSetting
const int angels[]  = {0, 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 180};
const int numAngles = sizeof(angels) / sizeof(angels[0]);
const int Times[3]  = {16, 15, 17};
const int numTime   = sizeof(Times)/sizeof(Times[0]);

//json
#define json_size 3800
char json [512];

//LoRa
#define devAddr "665a4695"
#define nwkSkey "665a4695f2fbcf8f6b9770716098926b"
#define appSkey "665a4695614dd02cec675eb1e009ad57"

#define csPin     5
#define resetPin  0
#define irqPin    27
