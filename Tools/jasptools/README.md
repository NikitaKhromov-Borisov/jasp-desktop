# jasptools
R package which aids developers with writing JASP analyses.

## Installation
It is necessary to install the package. Do this using either:

`install.packages("/%path%/jasp-desktop/Tools/jasptools/", repos = NULL, type = "source")`

or

`devtools::install("/%path%/jasp-desktop/Tools/jasptools/")`.

`devtools::install` can be useful because it will automatically install the dependencies of jasptools, whereas 
`install.packages` cannot do this.

After loading jasptools with `library(jasptools)`, you need to call `develop(%path_to_jasp-desktop%)`. This is 
required once after every reinstall of jasptools.

## Functionality
At the moment jasptools has four classes of functions.
Each of these functions has documentation you may view by the usual syntax, e.g., `?run`.

The general classes are:


### 1. Running JASP analyses
- `run`: run a JASP analysis
- `view`: view output of a JASP analysis
- `analysisOptions`: create options used by run

There are two general procedures to running analyses with jasptools.  
The first procedure uses the .json files to create option lists.
These lists will almost always require further editing.
#### Example 1
```
#create default options
options <- jasptools::analysisOptions("BinomialTest")

#we want to perform the binomial test on 'contBinom'
options[["variables"]] <- "contBinom"
jasptools::run("BinomialTest", dataset="debug.csv", options=options)
```

The second procedure uses syntax generated by Qt.  
Just start Qt once, set the options to your liking and copy the syntax from the Qt terminal.
#### Example 2
```
#create options from the Qt json string
options <- jasptools::analysisOptions('{
   "id" : 4,
   "name" : "BinomialTest",
   "options" : {
      "VovkSellkeMPR" : false,
      "confidenceInterval" : false,
      "confidenceIntervalInterval" : 0.950,
      "descriptivesPlots" : false,
      "descriptivesPlotsConfidenceInterval" : 0.950,
      "hypothesis" : "notEqualToTestValue",
      "plotHeight" : 300,
      "plotWidth" : 160,
      "testValue" : 0.50,
      "variables" : [ "contBinom" ]
   },
   "perform" : "run",
   "revision" : 1,
   "settings" : {
      "ppi" : 192
   }
}')
jasptools::run("BinomialTest", dataset="debug.csv", options=options)
```

It is not necessary to use a JASP dataset (such as the debug.csv file we showed in the examples), you may provide any 
data.frame to the dataset argument of the run function.

### 2. Testing JASP analyses
- `testAll`: test all analyses
- `testAnalysis`: test a specific analysis
- `inspectTestPlots`: validate a new plot or inspect differing plots
- `makeTestTable`: change the output of a JASP table to short, testable list

To ensure that no aspects of JASP are accidentally broken, we use unit testing.
These tests check if all tables still produce the same results, plots can be made, errors are caught, etc.
If an analysis is changed, it's a good idea to check that no unit test returns an error.
To this purpose jasptools offers convenience functions for testing.

### 3. Linting and Styling analyses

- `lintAnalysis`: test if an R file complies with the JASP syntax standards. For example, check if `<-` is used rather
than `=`. In addition, this function performs some check for code correctness. For example, it will give a warning if
an object is created but never used. Some of these correctness checks may give false positives that can be safely 
ignored. 
- `styleAnalysis`: apply a bunch of JASP syntax standards to an analysis. A safety copy is made before modifying a file.
This function will change tabs into spaces, change `=` into `<-` where appropriate, etc.

All changes that `styleAnalysis` can automatically apply to code are mandatory for R analyses. 

### 4. Modifying jasptools' setup
- `viewPkgOptions`: views settings in the package 
- `setPkgOption`: change a setting in the package (e.g., paths and ppi)

On startup jasptools will attempt to find all the resources it requires.
An example of one of these resources is the R library that comes bundled with JASP.
All of these resources, as well as some additional options are stored in the pkgOptions.
If you wish to change a resource jasptools uses you can set it through `setPkgOption`.


## Known limitations:
- Click actions in the browser are not supported (e.g., "save as")
- State and callbacks are ignored