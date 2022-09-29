#pragma once
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const enum properties {
    SHOW_ID,
    TYPE,
    TITLE,
    DIRECTOR,
    CAST,
    COUNTRY,
    DATA_ADDED,
    RELEASE_YEAR,
    RATING,
    DURATION,
    LISTED_IN,
    DESCRIPTION
};

class Show {
/*---------- Properties ----------*/

    /// @brief Unique ID for every Movie/Tv Show.
    string show_id;
    /// @brief Identifier - A Movie or TV Show.
    string type;
    /// @brief Title of the Movie/Tv Show.
    string title;
    /// @brief Director of the Movie/Tv Show.
    string director;
    /// @brief Actors involved in the Movie/Tv Show.
    vector<string> cast;
    /// @brief Country where the Movie/Tv Show was produced.
    string country;
    /// @brief Date it was added on Netflix.
    string data_added;
    /// @brief Actual Release year of the Movie/Tv Show.
    short release_year;
    /// @brief TV Rating of the Movie/Tv Show.
    string rating;
    /// @brief Total Duration - in minutes or number of seasons.
    string duration;
    /// @brief Genere.
    vector<string> listed_in;
    /// @brief The summary description.
    string description;

public:
/*---------- Constructors ----------*/

    Show() = default;
/*---------- Getters/Setters ----------*/

    string getShowId();
    void setShowId(string show_id);

    string getType();
    void setType(string type);

    string getTitle();
    void setTitle(string title);

    string getDirector();
    void setDirector(string director);

    vector<string> getCast();
    void setCast(vector<string> cast);

    string getCountry();
    void setCountry(string country);

    string getDataAdded();
    void setDataAdded(string data_added);

    short getReleaseYear();
    void setReleaseYear(short release_year);

    string getRating();
    void setRating(string rating);

    string getDuration();
    void setDuration(string duration);

    vector<string> getListedIn();
    void setListedIn(vector<string> listed_in);

    string getDescription();
    void setDescription(string description);
/*---------- Methods ----------*/

    void addCast(string actor);

    void addListedIn(string genere);

    void setProperties(string properties);
/*---------- toString ----------*/

    string toString();
};
