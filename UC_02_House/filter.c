#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void random_filter() {

char pahtFiltr[30] = "filters=";
char categories[30] = "[categories]=";
char media[30] = "[media]=";
int randNumberFilter;
srand(time(NULL));

switch(rand() % 9) {
	case 0:
		lr_save_string(lr_paramarr_random("AdministrativeDistrict"), "AdministrativeDistrictRand");
		strcat(pahtFiltr, lr_eval_string("{AdministrativeDistrictRand}"));
		strcat(categories, lr_eval_string("{AdministrativeDistrictRand}"));
		lr_save_string(lr_eval_string(pahtFiltr), "filter");
		lr_save_string(lr_eval_string(categories), "filterJSON");
		break;
	case 1:
		lr_save_string(lr_paramarr_random("ArchitecturalStyle"), "ArchitecturalStyleRand");
		strcat(pahtFiltr, lr_eval_string("{ArchitecturalStyleRand}"));
		strcat(categories, lr_eval_string("{ArchitecturalStyleRand}"));
		lr_save_string(lr_eval_string(pahtFiltr), "filter");
		lr_save_string(lr_eval_string(categories), "filterJSON");
		break;
	case 2:
		lr_save_string(lr_paramarr_random("VirtualTours"), "VirtualToursRand");
		strcat(pahtFiltr, lr_eval_string("{VirtualToursRand}"));
		strcat(categories, lr_eval_string("{VirtualToursRand}"));
		lr_save_string(lr_eval_string(pahtFiltr), "filter");
		lr_save_string(lr_eval_string(categories), "filterJSON");
		break;
	case 3:
		lr_save_string(lr_paramarr_random("CultBuildings"), "CultBuildingsRand");
		strcat(pahtFiltr, lr_eval_string("{CultBuildingsRand}"));
		strcat(categories, lr_eval_string("{CultBuildingsRand}"));
		lr_save_string(lr_eval_string(pahtFiltr), "filter");
		lr_save_string(lr_eval_string(categories), "filterJSON");
		break;
	case 4:
		lr_save_string(lr_paramarr_random("MemorialValue"), "MemorialValueRand");
		strcat(pahtFiltr, lr_eval_string("{MemorialValueRand}"));
		strcat(categories, lr_eval_string("{MemorialValueRand}"));
		lr_save_string(lr_eval_string(pahtFiltr), "filter");
		lr_save_string(lr_eval_string(categories), "filterJSON");
		break;
	case 5:
		lr_save_string(lr_paramarr_random("MoscowRestoration"), "MoscowRestorationRand");
		strcat(pahtFiltr, lr_eval_string("{MoscowRestorationRand}"));
		strcat(categories, lr_eval_string("{MoscowRestorationRand}"));
		lr_save_string(lr_eval_string(pahtFiltr), "filter");
		lr_save_string(lr_eval_string(categories), "filterJSON");
		break;
	case 6:
		lr_save_string(lr_paramarr_random("PurposeOfTheBuilding"), "PurposeOfTheBuildingRand");
		strcat(pahtFiltr, lr_eval_string("{PurposeOfTheBuildingRand}"));
		strcat(categories, lr_eval_string("{PurposeOfTheBuildingRand}"));
		lr_save_string(lr_eval_string(pahtFiltr), "filter");
		lr_save_string(lr_eval_string(categories), "filterJSON");
		break;
	case 7:
		lr_save_string(lr_paramarr_random("Age"), "AgeRand");
		strcat(pahtFiltr, lr_eval_string("{AgeRand}"));
		strcat(categories, lr_eval_string("{AgeRand}"));
		lr_save_string(lr_eval_string(pahtFiltr), "filter");
		lr_save_string(lr_eval_string(categories), "filterJSON");
		break;
	case 8:
		lr_save_string(lr_paramarr_random("Media"), "MediaRand");
		strcat(pahtFiltr, lr_eval_string("{MediaRand}"));
		strcat(media, lr_eval_string("{MediaRand}"));
		lr_save_string(lr_eval_string(pahtFiltr), "filter");
		lr_save_string(lr_eval_string(media), "filterJSON");
		break;
	default :
		break;

}
}