package com.example.study.blog.repository

import com.example.study.blog.entity.WordCount
import org.springframework.data.jpa.repository.JpaRepository
import org.springframework.data.repository.CrudRepository

interface WordRepository : JpaRepository<WordCount, String> {
    fun findTop10ByOrderByCntDesc(): List<WordCount>
}