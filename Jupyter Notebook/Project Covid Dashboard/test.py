import numpy as np
import pandas as pd
file = pd.read_csv("https://covid.ourworldindata.org/data/owid-covid-data.csv")
to_drp = ['iso_code', 'continent','total_cases', 'new_cases',
'new_cases_smoothed', 'total_deaths', 'new_deaths',
'new_deaths_smoothed', 'total_cases_per_million',
'new_cases_per_million',
'total_deaths_per_million', 'new_deaths_per_million',
'reproduction_rate', 'icu_patients',
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
'total_boosters_per_hundred',
'new_vaccinations_smoothed_per_million', 'stringency_index',
'population', 'population_density', 'median_age', 'aged_65_older',
'aged_70_older', 'gdp_per_capita', 'extreme_poverty',
'cardiovasc_death_rate', 'diabetes_prevalence', 'female_smokers',
'male_smokers', 'handwashing_facilities', 'hospital_beds_per_thousand',
'life_expectancy', 'human_development_index',
'excess_mortality_cumulative_absolute', 'excess_mortality_cumulative',
'excess_mortality', 'excess_mortality_cumulative_per_million']

file['new_deaths_smoothed_per_million'] = file['new_deaths_smoothed_per_million']/10000
file['new_cases_smoothed_per_million'] = file['new_cases_smoothed_per_million']/10000

file = file[file["location"]==input("Enter location: ").capitalize()]
file.drop(to_drp,inplace= True ,axis=1)

file = file.dropna()

import matplotlib.pyplot as pt
pt.xlabel("Fully Vaccinated")
pt.ylabel("Death")
pt.scatter(file["people_fully_vaccinated_per_hundred"],file['new_deaths_smoothed_per_million'])
pt.savefig("vaccination_vs_death")
pt.show()

pt.xlabel("Fully Vaccinated")
pt.ylabel("New Cases")
pt.scatter(file["people_fully_vaccinated_per_hundred"],file['new_cases_smoothed_per_million'])
pt.savefig("vaccination_vs_newcase")
pt.show()
file.to_csv("Vaccine.csv",index=False)
#print(file.head(10))