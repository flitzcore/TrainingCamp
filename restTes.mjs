'use strict';

import fs from 'fs';
import axios from 'axios';
import fetch from 'node-fetch';


/*
 * Complete the 'topArticles' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts INTEGER limit as parameter.
 * base url for copy/paste:
 * https://jsonmock.hackerrank.com/api/articles?page=<pageNumber>
 */

async function topArticles(limit) {
    console.log("limit: ", limit);
    let result = [];
    let totalDocuments= limit;
    let page =1
    while(totalDocuments>0){
        const response = await axios.get(`https://jsonmock.hackerrank.com/api/articles?page=${page}`);
        const page_num = response.data.page;
        const per_page= response.data.per_page;
        totalDocuments = response.data.total-(page_num*per_page);
        const articles = response.data.data;
        const filteredArticles = articles.filter(article => article.title || article.story_title);
        
        result.push(...filteredArticles);
        page++;
    }
    result = result.map(article => ({
        name: article.title || article.story_title,
        num_comments: article.num_comments || 0
    }));

  
    result.sort((a, b) => {
        if (a.num_comments > b.num_comments) {
            return -1;
        } else if (a.num_comments < b.num_comments) {
            return 1;
        } else {
            return a.name.localeCompare(b.name);
        }
    });

    return result.slice(0, limit).map(article => article.name);
}

async function main() {
    // const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const limit = 18;

    const result = await topArticles(limit);
    console.log(result);

    // ws.write(result.join('\n') + '\n');

    // ws.end();
}
main();