Action()
{	
	lr_start_transaction("TC_01_MainPage");
	
	web_url("{host}", 
		"URL={protocol}://{host}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t535.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("TC_01_MainPage", LR_AUTO);
	
	web_reg_save_param_regexp(
		"ParamName=rayonRoute",
		"RegExp=\\{\\\"id\\\":\\d*,\\\"slug\\\":\\\"([\\w-]+)\\\",\\\"image\\\":\\w*,\\\"active\\\":\\w*,\\\"parent\\\":458",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);
		
	web_reg_save_param_regexp(
		"ParamName=routeType",
		"RegExp=\\{\\\"id\\\":\\d*,\\\"slug\\\":\\\"([\\w\\d-]+)\\\",\\\"image\\\":\\w*,\\\"active\\\":\\w*,\\\"parent\\\":242",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=routesLength",
		"RegExp=\\\"slug\\\":\\\"(\\w*)\\\",\\\"nameWithT\\\":\\\"\\w*\\\"",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);
		
	web_reg_save_param_regexp(
		"ParamName=routesLengthNum",
		"RegExp=\\\"slug\\\":\\\"(\\w*)\\\",\\\"nameWithT\\\":\\\"\\w*\\\"[,\\\"\\w:\\[\\]]*\\\":(\\d+)",
		"NotFound=error",
		"Group=2",
		"Ordinal=All",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=multimedia",
		"RegExp=\\{\\\"id\\\":\\\"(\\w*)\\\",[\\w\\d\\\",:]+:\\[\\]\\}",
		"NotFound=error",
		"Group=1",
		"Ordinal=All",
		LAST);

	lr_start_transaction("TC_02_PageRoute");

	web_url("routes", 
		"URL={protocol}://{host}/routes", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protocol}://{host}/", 
		"Snapshot=t546.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("TC_02_PageRoute", LR_AUTO);
	
	random_filter();
	
	lr_start_transaction("TC_03_RandomFilter");

	web_url("routes_3", 
		"URL=https://um.mos.ru/routes?{filter}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t739.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_save_param_json(
		"ParamName=route",
		"QueryString=$.result[*].slug",
		"NotFound=warning",
		"SelectAll=Yes",
		LAST); 

	web_url("routes_6", 
		"URL=https://um.mos.ru/api/v1/routes?page=1&filter{filterJSON}",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://um.mos.ru/routes?{filter}", 
		"Snapshot=t754.inf", 
		"Mode=HTML", 
		LAST);
	
	if (atoi(lr_eval_string("{route_count}")) == 0) {
	lr_end_transaction("TC_03_RandomFilter", LR_AUTO);
	return 0;
	}
	
	lr_save_string(lr_paramarr_random("route"), "FilterRoute");

	web_reg_save_param_regexp(
		"ParamName=Audio",
		"RegExp=name\\\":\\\"\\D*\\\",\\\"audioFile\\\":\\\"(.*)\\\",\\\"announce",
		"NotFound=warning",
		"Group=1",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);

	web_reg_save_param_regexp(
		"ParamName=House",
		"RegExp=href=\\\"\\/houses\\/(.*?)\\\">",
		"NotFound=warning",
		"Group=1",
		"Ordinal=All",
		LAST);
	
	web_url("routeRand", 
		"URL=https://um.mos.ru/routes/{FilterRoute}",
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://um.mos.ru/routes?{filter}", 
		"Snapshot=t804.inf", 
		"Mode=HTML", 
		EXTRARES,  
		LAST);

	lr_end_transaction("TC_03_RandomFilter", LR_AUTO);
	
	if (strcmp(lr_eval_string("{Audio}"),"Success") ==0 ) {
	
	lr_start_transaction("TC_04_Audio");
	
	web_url("Audio",
		"URL=https://um.mos.ru{Audio}", 
		"TargetFrame=", 
		"Resource=0",
		"RecContentType=audio/mpeg",
		"Referer=https://um.mos.ru/routes/{FilterRoute}",
		"Snapshot=t805.inf",
		"Mode=HTML",
		EXTRARES,
		LAST);
	
	lr_end_transaction("TC_04_Audio", LR_AUTO);
	
	}
	
	lr_save_string(lr_paramarr_random("House"), "RandomHouse");

	if (strcmp(lr_eval_string("{RandomHouse}"),"Success") ==0 ) {
	
	lr_start_transaction("TC_05_TakeHouse");
	
	web_url("{RandomHouse}",
		        
		"URL={protocol}://{host}/houses/{RandomHouse}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t635.inf", 
		"Mode=HTML",
		EXTRARES,		
		LAST);
	
	lr_end_transaction("TC_05_TakeHouse", LR_PASS);
	
	}
	return 0;
}