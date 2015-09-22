{
  "targets": [
    {
      "target_name": "wrcard",
      "sources": [ "src/wrcard.cc"],
      "include_dirs": [
	  'src'
      ],
	  "msbuild_settings": {
			"Link": {
				"ImageHasSafeExceptionHandlers": "false"
			}
		}
    }
  ]
}
