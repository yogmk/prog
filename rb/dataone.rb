require "rubygems"
require "Nokogiri"

dd= `"c\:\\program Files\\GNUWin32\\bin\\wget.exe" --post-data "dataone=mkyogesh&password=Karvir_73" http://dataone.in/login.msc -O - 2>&1`

doc= Nokogiri::HTML(dd)

puts doc