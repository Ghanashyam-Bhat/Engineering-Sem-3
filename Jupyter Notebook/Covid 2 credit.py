def update_data_set():
    import requests
    csv_url = "https://covid.ourworldindata.org/data/owid-covid-data.csv"
    req = requests.get(csv_url)
    url_content = req.content
    csv_file = open('World_dataset.csv', 'wb')
    csv_file.write(url_content)
    csv_file.close()
  
def get_india():
    import numpy as np
    import pandas as pd
    file = pd.read_csv("World_dataset.csv")
    file.drop(file[file["iso_code"]!="IND"].index,inplace=True)
    file.reset_index(drop=True , inplace=True)
    
    
    to_drp = ['iso_code', 'continent', 'location',
       'new_cases_smoothed',
       'new_deaths_smoothed', 'total_cases_per_million',
       'new_cases_per_million', 'new_cases_smoothed_per_million',
       'total_deaths_per_million', 'new_deaths_per_million',
       'new_deaths_smoothed_per_million', 'reproduction_rate', 'icu_patients',
       'icu_patients_per_million', 'hosp_patients',
       'hosp_patients_per_million', 'weekly_icu_admissions',
       'weekly_icu_admissions_per_million', 'weekly_hosp_admissions',
       'weekly_hosp_admissions_per_million', 'new_tests', 'total_tests',
       'total_tests_per_thousand', 'new_tests_per_thousand',
       'new_tests_smoothed', 'new_tests_smoothed_per_thousand',
       'positive_rate', 'tests_per_case', 'tests_units', 'total_vaccinations',
       'people_vaccinated', 'people_fully_vaccinated', 'total_boosters',
       'new_vaccinations', 'new_vaccinations_smoothed',
       'total_vaccinations_per_hundred', 'people_vaccinated_per_hundred',
       'people_fully_vaccinated_per_hundred', 'total_boosters_per_hundred',
       'new_vaccinations_smoothed_per_million', 'stringency_index',
       'population', 'population_density', 'median_age', 'aged_65_older',
       'aged_70_older', 'gdp_per_capita', 'extreme_poverty',
       'cardiovasc_death_rate', 'diabetes_prevalence', 'female_smokers',
       'male_smokers', 'handwashing_facilities', 'hospital_beds_per_thousand',
       'life_expectancy', 'human_development_index',
       'excess_mortality_cumulative_absolute', 'excess_mortality_cumulative',
       'excess_mortality', 'excess_mortality_cumulative_per_million']
       
    file.drop(to_drp,inplace= True ,axis=1)
    print(file.fillna(0))
    file.to_csv("India_dataset.csv",index=False)
    
update_data_set()
get_india()

import matplotlib.pyplot as plt
import pandas as pd
file = pd.read_csv('India_dataset.csv')
#plt.scatter(file['date'],file['new_cases'])
width = 0.4
plt.bar(file['date'],file['new_deaths'],width, color='red')
plt.savefig('death.png')
plt.bar(file['date'],file['new_cases'], width , color='green')
plt.savefig('case.png')
#plt.legend(["New Death","New Case"])
plt.show()