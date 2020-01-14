# Module objectives #
**Name: Visitor Profile**
Create profile when vitor  votes on poll
collect geo information
creates ability to ask personal information on polls vote submit
create chart with the answers

# Requirements

GeoIP2 Library and account is for to track visitor location by ip
Custom Entityies:

**Profile**
properties :  id host created  
fields : geo_location, tags(from url's visited), personal_info_fields multivalued fieldset (fetched from polls)

**Visits**
properties : id profile_id time_visited url_visited

Extend poll node by checkbox whether question is for anonimous visitor profile 
on check box we will add a field to the all profiles according on question and will record the  answers according on host and cookie
so we could track as many visitors from ip but from diferebnt browsers or devices

    

