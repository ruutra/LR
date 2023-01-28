Action()
{	
	lr_start_transaction("TC_01_MainPage");

	web_url("{host}", 
		"URL={protocol}://{host}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t51.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("TC_01_MainPage", LR_AUTO);
	
	web_reg_save_param_regexp(
		"ParamName=AdministrativeDistrict",
		"RegExp=\\{\\\"id\\\"\\:\\d*,\\\"slug\\\":\\\"([\\w-]*)\\\"[\\w-:,\\\"]*parent\\\":388",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=ArchitecturalStyle",
		"RegExp=\\{\\\"id\\\"\\:\\d*,\\\"slug\\\":\\\"([\\w-]*)\\\"[\\w-:,\\\".\\d/]*parent\\\":2",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=VirtualTours",
		"RegExp=\\{\\\"id\\\"\\:\\d*,\\\"slug\\\":\\\"([\\w-]*)\\\"[\\w-:,\\\".\\d/]*parent\\\":6",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=CultBuildings",
		"RegExp=\\{\\\"id\\\"\\:\\d*,\\\"slug\\\":\\\"([\\w-]*)\\\"[\\w-:,\\\".\\d/]*parent\\\":8",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=MemorialValue",
		"RegExp=\\{\\\"id\\\"\\:\\d*,\\\"slug\\\":\\\"([\\w- ]*)\\\"[\\w-:,\\\".\\d/]*parent\\\":4",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=MoscowRestoration",
		"RegExp=\\{\\\"id\\\"\\:\\d*,\\\"slug\\\":\\\"([\\w- ]*)\\\",[^,]*[\\w-:,\\\".\\d/ ]*parent\\\":5",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=PurposeOfTheBuilding",
		"RegExp=\\{\\\"id\\\"\\:\\d*,\\\"slug\\\":\\\"([\\w- ]*)\\\",[^,]*[\\w-:,\\\".\\d/ ]*parent\\\":3",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);
		
	web_reg_save_param_regexp(
		"ParamName=Age",
		"RegExp=\\{\\\"id\\\"\\:\\d*,\\\"slug\\\":\\\"([\\w- ]*)\\\",[^,]*[\\w-:,\\\".\\d/ ]*parent\\\":1",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=Media",
		"RegExp=\\{\\\"id\\\":\\\"(\\w*)\\\",[\\w\\d\\\",:]+:\\[\\]\\}",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);
	
	lr_start_transaction("TC_02_PageHouse");


	web_url("houses", 
		"URL={protocol}://{host}/houses", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protocol}://{host}/", 
		"Snapshot=t72.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TC_02_PageHouse", LR_AUTO);
	
	random_filter();
	
	web_reg_save_param_json(
		"ParamName=house",
		"QueryString=$.result[*].slug",
		"NotFound=warning",
		"SelectAll=Yes",
		LAST);
	
	lr_start_transaction("TC_03_RandomFilterHouse");

	web_url("houses_3", 
		"URL={protocol}://{host}/api/v1/houses?page=1&filter{filterJSON}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={protocol}://{host}/houses?{filter}", 
		"Snapshot=t103.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("houses_4", 
		"URL={protocol}://{host}/houses?{filter}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t107.inf", 
		"Mode=HTML", 
		LAST);
	
	if (atoi(lr_eval_string("{house_count}")) == 0) {
	lr_end_transaction("TC_03_RandomFilterHouse", LR_AUTO);
	return 0;
	}
	
	lr_save_string(lr_paramarr_random("house"), "HouseRand");


	web_reg_save_param_regexp(
		"ParamName=Audio",
		"RegExp=\\\"audioFile\\\":\\\"([\\d\\w/ .]*)\\\",",
		"NotFound=warning",
		"Group=1",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	
	
	web_url("houseRand", 
		"URL=https://um.mos.ru/houses/{HouseRand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t137.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);
	
	lr_end_transaction("TC_03_RandomFilterHouse", LR_AUTO);
	
	if (strcmp(lr_eval_string("{Audio}"),"Success") ==0 ) {
	
	lr_start_transaction("TC_04_AudioHouse");

	web_url("HouseRand", 
		"URL={protocol}://{host}/houses/{HouseRand}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t130.inf", 
		"Mode=HTML", 
		EXTRARES,  
		"Url=..{Audio}", ENDITEM, 
		LAST);
	
	lr_end_transaction("TC_04_AudioHouse", LR_AUTO);

	}
	
	return 0;
}