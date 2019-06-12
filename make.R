# Script to convert .Rd and .Rmd files from man/ and vignettes to docs/*.md for use by MkDocs
library("Rd2md")
library("knitr")

path = "man/"
files = dir(path)

for(file in files){
  infile = file.path(path, file)
  outfile = file.path("docs", gsub(".Rd", ".md", file))
  Rd2markdown(infile, outfile, append = FALSE)
}

vignette_file = dir("vignettes/")
Rmds = vignette_file[grep(".Rmd",vignette_file)]
in_ = file.path("vignettes", Rmds)
out_ = file.path("docs", gsub(".Rmd", ".md", Rmds))
sapply(1:length(in_),function(x) knit(in_[x],out_[x]))


file_rename = function(from, to) {
    todir = dirname(to)
    if (!isTRUE(file.info(todir)$isdir)) dir.create(todir, recursive=TRUE)
    file.rename(from = from,  to = to)
}

figures = dir("figure/")
for (f in figures){
  file_rename(from = file.path("figure", f),
              to = file.path("docs", "figure", f))
}

file_rename(from = file.path("README.md"),
            to = file.path("docs", "index.md"))