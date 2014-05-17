#!/usr/bin/env ruby

require "rubygems"
require "win32ole"
require "Nokogiri"


# download the data
# parse xml and extract data of interest
# create/populate the Excel.

$twoD_arr= Array.new

def parse_data(dd)
  doc = Nokogiri::HTML(dd)
  x = Array.new
  
  # we need a more robust 'xpath' here. This one looks fragile.
  tbl=doc.xpath('//table[preceding::table[@class="jiraform  maxWidth"]][1]//tr//a[@href]')
  tbl.each {|node|
    if node.inner_text =~ /^TI0739\-.*/ or node.inner_text =~ /[0-9]+/
      x.push(node.inner_text)
      #puts "DEBUG: node text =>#{node.inner_text}<="
    end
  }
  arr_to_2d(x)
  #puts "DEBUG: \$twoD_arr=#{$twoD_arr}"
end


def arr_to_2d(arr)
  while arr != []
    pair=[arr.slice!(0,1), arr.slice!(0,1)].flatten  
    $twoD_arr.push(pair)
    arr_to_2d(arr)
  end
  
end


def populate_excel()
  xl = WIN32OLE.new('Excel.Application')

  xl.visible = 1
  begin
    #wb = xl.Workbooks.Add    # To add new
    # update existing
    wb= xl.Workbooks.Open('V:\Analysis\Sabre\Testing-and-JIRA-Status.xlsx')
  rescue
      p "Open () errored. Is the FIle already open? Close & run again"
  end
  
  #ws= wb.Worksheets(1)
  #ws.name = 'JIRA summary'

  ws= wb.Worksheets("summary")

  $twoD_arr.each do | row|  
    case row[0].to_s
      when /MIGR-CABS.*TAL/
        ws.Range("P9").Value = row[1].to_s
      when /MIGR-CABS.*SED/
        ws.Range("Q9").Value = row[1].to_s
      when /MIGR-SABRE.*TAL/
        ws.Range("P8").Value = row[1].to_s
      when /MIGR-SABRE.*SED/
        ws.Range("Q8").Value = row[1].to_s
      when /MIGR-MARS.*TAL/
        ws.Range("P7").Value = row[1].to_s
      when /MIGR-MARS.*SED/
        ws.Range("Q7").Value = row[1].to_s
      when /INTG-MARS.*TAL/
        ws.Range("S7").Value = row[1].to_s
      when /INTG-MARS.*SED/
        ws.Range("T7").Value = row[1].to_s
      when /INTG-MARS.*LVD/
        ws.Range("u7").Value = row[1].to_s
      when /EUIT-MARS.*TAL/
        ws.Range("w7").Value = row[1].to_s
      when /EUIT-MARS.*SED/
        ws.Range("x7").Value = row[1].to_s
      when /EUIT-MARS.*LVD/
        ws.Range("Y7").Value = row[1].to_s
    end
  end

  #ws.Range("P5:y5").Merge
  #ws.Range("P5:y5").FormulaR1C1 = "JIRAs raised and REsolved"
  #ws.Range("P5:Y5").HorizontalAlignment = -4108

  #wb.SaveAs('c:\home\ymk\..')
  wb.Save

  wb.close

  xl.Quit
  data=nil
  $two_D_arr= nil
end


# execution --

# scrape the web page!
data= %x{c\:\\bin\\wget --no-check-certificate  --post-data "os_username=venyog&os_password=p-o0i9u8&os_cookies=True" https://jira.tds.net/secure/ManageFilters.jspa -O - 2>&1}

if $?.exitstatus != 0 
  puts "error: could not get JIRA details from web page. 
        Cannot continue."
  exit -1
end

parse_data(data)

# back up yesterday's file just to be safe.
require "FileUtils"
FileUtils.cp 'V:\Analysis\Sabre\Testing-and-JIRA-Status.xlsx', 'V:\Analysis\Sabre\Copy of Testing-and-JIRA-Status.xlsx'

# or keep it simple
#`copy "V:\Analysis\Sabre\Testing-and-JIRA-Status.xlsx" "V:\Analysis\Sabre\Copy of Testing-and-JIRA-Status.xlsx"`
#if $?.exitstatus != 0
#then
#  puts "Could not back up the file. Won't proceed with update"
#  exit -1
#end

populate_excel

#--
