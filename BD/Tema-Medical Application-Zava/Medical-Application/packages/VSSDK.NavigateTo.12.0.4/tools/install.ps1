param($installPath, $toolsPath, $package, $project)

foreach ($reference in $project.Object.References)
{
	switch -regex ($reference.Name.ToLowerInvariant())
	{
	"^microsoft\.visualstudio\.language\.navigateto\.interfaces$"
		{
			$reference.CopyLocal = $false;
		}
	default
		{
			# ignore
		}
	}
}
