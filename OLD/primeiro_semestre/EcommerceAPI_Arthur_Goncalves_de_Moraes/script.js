console.log('Começou');

fetch('https://fakestoreapi.com/products?limit=18')
  .then(res => res.json())
  .then(data => {
    console.log('Imprimindo produtos');
    let str = '';
    for (let i = 0; i < data.length; i++) {
      let produtos = data[i];
      let title = produtos.title.length > 20 ? produtos.title.substring(0, 20) + '...' : produtos.title;
      str += `<div class="searchbarItem">
                <div class="card h-100">
                  <img id="produtoimg" src="${produtos.image}" class="card-img-top" alt="...">
                  <div>
                    <h5 class="card-title">${title}</h5>
                    <p class="card-text">Avaliação: ${produtos.rating.rate}/5</p>
                    <p class="card-text">R$${produtos.price}</p>
                    <a href="detalhes.html?id=${produtos.id}" target="_blank" class="btn btn-primary">Mais detalhes</a> 
                  </div>
                </div>
              </div>`;
    }
    document.getElementById('tela').innerHTML = str;
  });

console.log('Terminou');

document.addEventListener("DOMContentLoaded", function() {
  var searchInput = document.getElementById("searchInput");
  searchInput.addEventListener("input", search);
  function search() {
    // Get the search query from the input field
    var searchQuery = searchInput.value.trim();

    // Clear previous search results if the search query is empty
    if (searchQuery === "") {
      clearSearchResults();
      return;
    }

    // Clear previous search results
    var searchResultsDiv = document.getElementById("searchResults");
    searchResultsDiv.innerHTML = "";

    // Make a request to the API to retrieve all items
    fetch("https://fakestoreapi.com/products?limit=50")
        .then(response => response.json())
        .then(data => {
            // Filter the items based on the search query
            var filteredItems = data.filter(item => item.title.toLowerCase().includes(searchQuery.toLowerCase()));

            // Process the filtered items
            if (filteredItems.length > 0) {
                filteredItems.forEach(item => {
                    // Create a button element for each search result
                    var resultButton = document.createElement("button");
                    resultButton.textContent = item.title;
                    resultButton.addEventListener("click", function() {
                        // Redirect to the details.html page passing the item ID as a query parameter
                        window.location.href = "detalhes.html?id=" + item.id;
                    });

                    searchResultsDiv.appendChild(resultButton);
                });
            } else {
                // No results found
                var noResultsDiv = document.createElement("div");
                noResultsDiv.textContent = "Sem resultados.";
                searchResultsDiv.appendChild(noResultsDiv);
            }
        })
        .catch(error => {
            // Handle any errors
            console.log("Error: " + error);
        });
}
function clearSearchResults() {
  var searchResultsDiv = document.getElementById("searchResults");
  searchResultsDiv.innerHTML = "";
}

});



