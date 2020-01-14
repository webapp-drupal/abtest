# Module objectives 
**Name: Visitor Profile**
Create profile for the anonimous visitor when poll voited. Collect all votes and page visits on profile. Collect geo location via GEOIP2. Collect personal information and store it in proifile


# Requirements

GeoIP2 Library and account is for to track visitor location by ip

# Custom Entityies:

**Profile**
properties :  id host time_created  
fields : geo_location, tags(from url's visited), personal_info_fields multivalued fieldset (fetched from polls)

**Visits**
properties : id profile_id time_visited url_visited

**Extending Polls functionality**
Alter the form for the creation off polls. Extend poll node by checkbox whether question is for anonimous visitor profile 
on check box open field to fill the personal question add form to submit habdler to collect personal questions answer
save the answer in profile. Save poll answer to the  profile


    

