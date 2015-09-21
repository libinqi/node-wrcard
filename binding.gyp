{
  "targets": [
    {
      "target_name": "wrcard",
      "sources": [ "addon/wrcard.cc"],
      "include_dirs": [
	  'addon'
      ],
	  "msbuild_settings": {
			"Link": {
				"ImageHasSafeExceptionHandlers": "false"
			}
		}
    }
  ]
}
