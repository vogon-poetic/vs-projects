var express = require('express');
var request = require('request');
var cheerio = require('cheerio');
var fs = require('fs');
var app = express();

app.get('/scrape', function (req, res) {
    // all of the web-scraping shall happen here.

    var url = 'https://www.rottentomatoes.com/m/sorry_to_bother_you_2018';
    request(url, function (error, response, html) {
        if (!error) {
            var $ = cheerio.load(html);

            var title, release, rating;
            var json = { title: "", release: "", rating: "" };

            $('.panel_heading::before').filter(function () {
                var data = $(this);
                title = data.children().first().text();
                json.title = title;
            });
        }
    })
});

app.listen('8081');
console.log('started on port 8081');
exports = modules.exports = app;
