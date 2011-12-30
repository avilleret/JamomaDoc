#!/usr/bin/ruby -wKU
# TAP: changed the above so that on the Mac it always uses the version of ruby installed by the OS
# this is because version 1.8.7 works, but 1.9.1 does not
#/usr/bin/env ruby -wKU

require "FileUtils"

glibdir = "."
Dir.chdir glibdir
glibdir = Dir.pwd

search = `find . -name *maxref.yml` #Does this only work on OSX ?

puts search

maxrefs = Array::new
maxrefs = search.split("\n")
# Create refpages folder and copy XLS file for Max 5  - comment this out if you don't want it
FileUtils.mkdir_p("/Applications/Max5/patches/docs/refpages/jamoma-ref") unless File.exist?("/Applications/Max5/patches/docs/refpages/jamoma-ref")
`cp "#{glibdir}/max/support/refpages/_jdoc_ref_common.xsl" /Applications/Max5/patches/docs/refpages/jamoma-ref`
# Create refpages folder and copy XLS file for Max 6  - comment this out if you don't want it
FileUtils.mkdir_p("/Applications/Max6/patches/docs/refpages/jamoma-ref") unless File.exist?("/Applications/Max6/patches/docs/refpages/jamoma-ref")
`cp "#{glibdir}/max/support/refpages/_jdoc_ref_common.xsl" /Applications/Max6/patches/docs/refpages/jamoma-ref`

maxrefs.each do |ref|
 dest = ref.sub(/\.(.*jcom.*maxref)\.yml/,"#{glibdir}"'\1.xml')
 ref = ref.sub(/\.(.*jcom.*maxref.yml)/,"#{glibdir}"'\1')
`ruby #{glibdir}/yaml-to-maxref.rb #{ref} #{dest}`
# Copy refpages into Max 5  - comment this out if you don't want it
`cp #{dest} /Applications/Max5/patches/docs/refpages/jamoma-ref`
# Copy refpages into Max 6  - comment this out if you don't want it
`cp #{dest} /Applications/Max6/patches/docs/refpages/jamoma-ref`

end
